_This project has been created as part of the 42 curriculum by ponsumri_

# Explanation

## Please read — notes I wrote myself ❤︎

### Why buffering exists

Three buffering modes in `setvbuf`:

- `_IONBF` — no buffer, every stdio call becomes a syscall immediately
- `_IOLBF` — buffer exists, flush triggered by the `\n` character
- `_IOFBF` — buffer exists, flush triggered only when the buffer is full

**Why do we need a buffer if we could just read directly?**

Because using a syscall (`read()`, `write()`) into the kernel is expensive. What makes it expensive? First you need to understand how a syscall differs from a regular function call.

### CPU privilege rings

x86 CPUs (and most architectures) have privilege levels — "rings."

- User programs run in **Ring 3** (restricted — can't touch hardware directly, can't access arbitrary memory).
- The kernel runs in **Ring 0** (full access — memory management, device drivers, hardware I/O).

Our C program's `fwrite` eventually needs the `write()` syscall, because data must physically go to disk. Disk access is hardware access, which is a kernel-only operation. Ring 3 code cannot do this directly — it must ask the kernel.

When we call `write(fd, buf, 4096);`:

```
Ring 3 → Ring 0 → kernel does the work → kernel finishes the work → back to Ring 3
```

```c
// bad: ~1,000,000 syscalls, called every time
for (int i = 0; i < 1000000; i++) {
    write(fd, &byte, 1);      // raw syscall, no buffering
}

// good: ~1,000,000 / 8192 ≈ 122 syscalls, far fewer
for (int i = 0; i < 1000000; i++) {
    fwrite(&byte, 1, 1, fp);  // buffered, batches into 8KB chunks before syscall
}
fclose(fp);
```

### Why `ssize_t`

Because it's signed, and a signed type lets us hear the kernel's error signal.

```c
int fd = -5;             // garbage or already-closed fd
read(fd, buf, size);      // returns -1
```

### Why we don't need `sizeof(char)` here

Because `sizeof(char)` is always `1`, so:

```c
bucket = malloc(oldlen + newlen + 1);
```

is exactly the same as:

```c
bucket = malloc((oldlen + newlen) * sizeof(char) + 1);
```

# Problems

# Resources

- [Understanding Ring 0 to Ring 3: the hidden layers of virtualization](https://medium.com/@leoyeh.me/understanding-ring-0-to-ring-3-the-hidden-layers-of-virtualization-d10e0fe5a798)

# Pseudo code

# Variable

# Define value

A static variable's lifetime spans the entire process.

```
ulimit -n 1024
```

# Header explanation

```c
#ifndef GET_NEXT_LINE_H
    # define GET_NEXT_LINE_H
    # include <stdio.h>  // for malloc free
    # include <stdlib.h> // for what ? i forgot claude do something here 
    # include <unistd.h> // for size_t ssize_t
    # ifndef BUFFER_SIZE // Because In Subject Page 8 We can complie without the -D and when we dont have this condition and we dont check if its already have BUFFER_SIZE its gonna replace with default buffer_size
        # define BUFFER_SIZE 42
    # endif

    typedef struct s_gnl_list
    {
        int fd;                    // 1 byte in theory, but memory padding rounds it up to 4
        char *buf;                 // 8 bytes
        struct s_gnl_list *next;   // 8 bytes
    }   t_gnl_list;

    t_gnl_list	*lstfind(t_gnl_list *head, int fd);
    t_gnl_list	*lstcreate(int fd);
    t_gnl_list	*lstinsert(t_gnl_list **head, t_gnl_list *new_node);
    void		lstremove(t_gnl_list **head, int fd);
    char		*lstcombine(char *old_str, char *new_str);
    int			find_newline(char *s);
    size_t		ft_strlen(char *s);
    void		ft_memcpy(char *dst, char *src, size_t n);

#endif
```

**Struct memory layout (24 bytes total, with padding):**

| byte  | 0-3 | 4-7 | 8-15 | 16-23 |
|-------|-----|-----|------|-------|
| field | `fd` | padding | `buf` | `next` |

Most processors read memory in 8-byte chunks (4 bytes on 32-bit systems), which is why the padding exists.

**Is this the first time `get_next_line` is called for this `fd`?**

→ `lstfind` doesn't find it → a new node is created with `lstcreate` and linked into the list with `lstinsert`.