*This project has been created as part of the 42 curriculum by ponsumri*

# Description

`get_next_line` is a C function that reads a text file (or stdin) one line at a time across repeated calls, without ever loading the whole file into memory at once. It reads in fixed-size chunks (`BUFFER_SIZE`) directly via the `read()` syscall, buffers leftover data between calls using a `static` variable, and returns each line — including its trailing `\n` when one exists — until the file is exhausted, at which point it returns `NULL`.

The bonus part extends this to track multiple file descriptors independently and simultaneously, using exactly one static variable regardless of how many fds are open at once.

# Instructions

**Compilation (mandatory part):**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c <your_test_main>.c -o gnl_test
```

Also compiles without the `-D BUFFER_SIZE` flag, using the internal default (42):

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c <your_test_main>.c -o gnl_test
```

**Compilation (bonus part):**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c <your_test_main>.c -o gnl_bonus_test
```

**Usage example:**

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int   fd;
	char  *line;

	fd = open("some_file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

Also works by passing `0` as the fd to read from stdin instead of a file.

# Explanation

Personal notes written while building `get_next_line` — kept here so I can explain every design choice during defense without hesitating.

---

## 1. Why buffering exists

### The three buffering modes (`setvbuf`)

| Mode | Behavior |
|---|---|
| `_IONBF` | No buffer — every stdio call becomes a syscall immediately |
| `_IOLBF` | Buffered, flush triggered by the `\n` character |
| `_IOFBF` | Buffered, flush triggered only when the buffer is full |

### Why do we need a buffer if we could just read directly?

Because a syscall (`read()`, `write()`) into the kernel is expensive. To understand why, you need to understand how a syscall differs from a regular function call.

### CPU privilege rings

x86 CPUs (and most architectures) have privilege levels, called "rings."

- User programs run in **Ring 3** — restricted. Can't touch hardware directly, can't access arbitrary memory.
- The kernel runs in **Ring 0** — full access. Memory management, device drivers, hardware I/O.

Our program's `fwrite` eventually needs the `write()` syscall, because data must physically go to disk. Disk access is hardware access, which is kernel-only. Ring 3 code cannot do this directly — it must ask the kernel.

When we call `write(fd, buf, 4096);`:

```
Ring 3 → Ring 0 → kernel does the work → kernel finishes → back to Ring 3
```

Every crossing has a real cost (context switch, privilege check). That's the expense — not the data transfer itself.

```c
// bad: ~1,000,000 syscalls, one per byte
for (int i = 0; i < 1000000; i++) {
    write(fd, &byte, 1);      // raw syscall, no buffering
}

// good: ~1,000,000 / 8192 ≈ 122 syscalls
for (int i = 0; i < 1000000; i++) {
    fwrite(&byte, 1, 1, fp);  // buffered, batches into 8KB chunks before syscall
}
fclose(fp);
```

This is the same reasoning behind `get_next_line` reading in `BUFFER_SIZE` chunks instead of one byte at a time with raw `read()` — fewer syscalls, same idea as `fwrite`'s internal buffering.

---

## 2. File descriptors — what `fd` actually is

`fd` is the number the OS hands back when a file is opened, and the same number we pass into `read(fd, dst, BUFFER_SIZE)` every time.

- `0` = stdin, `1` = stdout, `2` = stderr — reserved by convention before any `open()` call.
- The OS assigns the **lowest available number** on `open()`, so the first file opened by a program typically gets `3`.
- `fd` is *not* the file itself and *not* its name. Opening the same file twice gives two different `fd`s with two independent read positions (offsets) — the kernel tracks the offset per open-file-description, not per filename.
- Because of this, `fd` is what the bonus implementation uses as the key in the linked list: it's the only thing guaranteed to be unique per "open instance," which is exactly what's needed to keep buffers from different files separate when reading them interleaved.
- Subject note (Chapter VII): a file descriptor doesn't only point to a regular file — it can be a pipe, stdin, etc. Code must not assume regular-file behavior.

---

## 3. Why `ssize_t`

Because it's signed, and a signed type lets us hear the kernel's error signal.

```c
int fd = -5;              // garbage or already-closed fd
read(fd, buf, size);      // returns -1
```

`size_t` (unsigned) can't represent `-1` meaningfully — it would wrap around to a huge positive number. `ssize_t` exists specifically so syscalls like `read()` can return a negative value to signal "something went wrong," separate from `0` which means "nothing left to read" (EOF).

---

## 4. Why we don't need `sizeof(char)`

Because `sizeof(char)` is always `1` by definition in C, so:

```c
bucket = malloc(oldlen + newlen + 1);
```

is exactly equivalent to:

```c
bucket = malloc((oldlen + newlen) * sizeof(char) + 1);
```

Multiplying by 1 changes nothing — writing `sizeof(char)` here is just noise.

---

## 5. Static variables

A static variable's lifetime spans the entire process — it keeps its value between function calls instead of being destroyed when the function returns. This is the mechanism that lets `get_next_line` "remember" where it left off reading, without any global variable (which the subject forbids).

- **Mandatory part**: no limit on the number of static variables used.
- **Bonus part**: exactly **one** static variable allowed, regardless of how many file descriptors are tracked at once. In this implementation that one static variable is the list `head` pointer — everything else (individual node buffers) lives on the heap, reached *through* that one static pointer, which is why it still counts as one static variable even though it manages many fds.

### Why `r = 1;` before the read loop

If `r` isn't given a value before the `while (r > 0 && ...)` check, it holds an undefined garbage value the first time it's read — undefined behavior. Setting it to any value `> 0` guarantees the loop body runs at least once, where `r` is immediately overwritten with the real result of `read()`.

---

## 6. Pointers used in this project

Two pointer patterns come up constantly and are worth being able to explain cold:

**Single pointer (`t_gnl_list *node`)** — used when a function only needs to read or modify the *data* a pointer already points to (e.g. `node->buf = ...`). The pointer itself never needs to change where it points.

**Double pointer (`t_gnl_list **head`)** — used when a function must change *what the caller's pointer variable points to* (e.g. inserting a new node at the head of the list). Since C passes arguments by value, a function receiving a plain `t_gnl_list *head` would only modify its own local copy of the pointer; the caller's `head` would be unaffected. Passing `&head` gives the function the address of the caller's actual pointer variable, so `*head = new_node;` reaches through and updates the real thing.

**Head insertion order matters**: when linking a new node into the list, the old head must be saved into the new node's `next` field *before* `head` itself is overwritten — otherwise the previous list is permanently lost (nothing points to it anymore, and it becomes unreachable and unfreeable).

```c
node->next = *head;   // save the old head first — like a temp variable in a swap
*head = node;          // now safe to overwrite
```

---

## 7. `ulimit -n`

```
ulimit -n 1024
```

Sets the maximum number of file descriptors a single process can have open at once (default is often 1024 on Linux). Relevant for testing the bonus part: if a test opens many files without closing them, this is the ceiling before `open()` starts failing with "too many open files."

---

## 8. Header file, explained line by line

```c
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>  // malloc, free
# include <unistd.h>  // read, ssize_t

# ifndef BUFFER_SIZE
// Subject page 8: the project must compile with AND without -D BUFFER_SIZE.
// This guard means: only define our own default if the compiler
// wasn't already given one via -D BUFFER_SIZE=n.
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_list
{
	int					fd;    // 4 bytes
	char				*buf;  // 8 bytes
	struct s_gnl_list	*next; // 8 bytes
}	t_gnl_list;

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

**Correction from my earlier draft**: `malloc`/`free` are declared in `<stdlib.h>`, not `<stdio.h>` — I had that backwards. `<stdio.h>` isn't needed here at all since nothing from it (`printf`, `fopen`, etc.) is used in this header or its functions. Removed it.

### Struct memory layout (24 bytes total, with padding)

| byte | 0–3 | 4–7 | 8–15 | 16–23 |
|---|---|---|---|---|
| field | `fd` | padding | `buf` | `next` |

Most processors read memory in 8-byte chunks (4 bytes on 32-bit systems). `fd` is only 4 bytes, but the next field (`buf`, a pointer) needs to start on an 8-byte boundary for the CPU to read it efficiently — so the compiler inserts 4 bytes of unused padding between `fd` and `buf`. This is why the struct is 24 bytes instead of the 20 you'd get by adding the fields naively (4 + 8 + 8 = 20).

---

## 9. Comma operator

The pattern `(expr1, expr2)` evaluates `expr1` first (for its side effect), discards its result, then evaluates `expr2` — whose value becomes the value of the whole expression.

```c
return (free_node(head, fd), line);
// equivalent to:
free_node(head, fd);
return (line);
```

```c
return (free(line), NULL);
// equivalent to:
free(line);
return (NULL);
```

Used here to run a cleanup call and return a value in one line, keeping `build_line` under the norm's 25-line-per-function limit. Safe in both cases because `free_node` and `free` return `void` — there's no meaningful return value being discarded.

---

## 10. High-level flow (pseudocode)

**Is this the first time `get_next_line` is called for this `fd`?**

```
lstfind(head, fd)
  → found?  return that node (it already holds leftover data from a previous call)
  → not found?  lstcreate(fd) makes a new node, lstinsert links it into the list
```

**Every call, after getting the node:**

```
1. keep reading into the node's buffer until either:
   - a '\n' is found in the buffer, or
   - read() returns 0 (EOF) or a negative value (error)
2. if nothing was ever read and the buffer is still empty → return NULL, remove the node
3. otherwise, split the buffer at the newline:
   - the part up to and including '\n' → returned to the caller
   - anything after it → copied into a fresh block, kept in the node for the next call
   - if there was nothing left after the split → remove the node entirely
```

---

## 11. Algorithm justification

A linked list keyed by `fd` was chosen over a fixed-size array because file descriptors are not guaranteed to be small or contiguous (e.g. `3, 4, 7`), and the number of fds in use at once isn't known ahead of time. A list grows exactly as needed with no wasted allocation, and lookup by `fd` is a simple linear scan — acceptable here since the number of simultaneously-tracked fds is expected to be small in practice.

Reading proceeds in fixed `BUFFER_SIZE` chunks rather than reading the whole file up front, per the subject's explicit requirement to minimize `read()` calls and never load more than necessary. Each chunk is appended to the fd's buffered leftover via `lstcombine` until a `\n` is found or `read()` signals EOF/error, at which point the buffer is split: the completed line is returned, and any remainder is kept for the next call.

# Resources

- [Understanding Ring 0 to Ring 3: the hidden layers of virtualization](https://medium.com/@leoyeh.me/understanding-ring-0-to-ring-3-the-hidden-layers-of-virtualization-d10e0fe5a798)
- [Understanding Comma Operator When return](https://stackoverflow.com/questions/32094189/comma-separated-return-arguments-in-c-function)

**How AI was used** *(fill in honestly before submitting — subject requires this explicitly, see Chapter V):*

- AI was used to explain concepts (pointers, static variables, syscalls, file descriptors) through guided questioning rather than to generate the implementation.
- List specifically which parts, if any, involved AI-assisted debugging (e.g. `TOO_MANY_LINES` norm fix, malloc-failure edge case review) versus parts written independently.
- Be specific and honest — this section is graded, and vague answers like "used AI for help" don't meet the requirement.