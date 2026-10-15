*This project has been created as part of the 42 curriculum by ponsumri.*

# ft_printf

## Description 

Printf is a function used to print formatted text and data to the standard output stream . defined within the <stdio.h> header file.
Recreates printf's core functionality: format string parsing,
variadic args, output formatting for %d, %s, %c, %x, %p, %%.

```c
int ft_printf(const char *format, ...);
```

## Instructions

### How each file works

| File | Role |
|------|------|
| `ft_printf.c` | Entry point. Walks `format` char by char. On `%` + a valid thing it calls `ft_format`, which pulls the matching argument with `va_arg` and dispatches to the right printer. Everything else is written as-is. Keeps a running `total` of bytes written and returns it (or `-1` on error). in this case 	if (!format) return (-1); we also handle more than printf that will be more safety |
| `ft_out.c` | The single write gate. `write(1, s, len)`, adds `len` to `total`, and latches `total = -1` if a write fails so every later call short-circuits. |
| `ft_putchar_print.c` | `%c` and `%%`. Writes one byte via `ft_out`. |
| `ft_putstr_print.c` | `%s`. Substitutes `"(null)"` for a `NULL` pointer, then writes `ft_strlen(s)` bytes. |
| `ft_putnbr_print.c` | `%d` / `%i`. Handles `INT_MIN` as a literal, prints `-` for negatives, then recurses on `n / 10` and writes `n % 10 + '0'`. |
| `ft_putun_print.c` | `%u`. Same recursion as `ft_putnbr` but on `unsigned int`, no sign handling. |
| `ft_putx_print.c` | `%x` / `%X`. Recurses on `n / 16` and indexes into the `base` string (`"0123456789abcdef"` or uppercase). |
| `ft_putptr_print.c` | `%p`. Prints `(nil)` for `NULL`, otherwise `0x` + the address as lowercase hex via `ft_puthex_print`. |
| `ft_strlen.c` | Counts bytes up to `'\0'`. Used by `ft_putstr_print`. |
| `ft_printf.h` | Prototypes and the `<unistd.h>` / `<stdarg.h>` includes. |

### Working with `va_arg`

```c
va_list args;

va_start(args, format);            // init: last named parameter is `format`

va_arg(args, int);                 // %c, %d, %i  (char/short are promoted to int)
va_arg(args, char *);              // %s
va_arg(args, void *);              // %p
va_arg(args, unsigned int);        // %u, %x, %X

va_end(args);                      // cleanup
```

Notes:
- `%c` reads an `int`, not a `char` — default argument promotion.
- `%%` consumes no argument, so `ft_format` never calls `va_arg` for it.
- The `va_list` is passed to helpers by address (`va_list *`) so a single cursor advances across the whole format string.

### Usage

```bash
make                 # builds libftprintf.a
```

```c
#include "ft_printf.h"

int len = ft_printf("%s has %d items (%c), addr %p\n", "cart", 3, 'x', &len);
// -> cart has 3 items (x), addr 0x7ffe...
// len = number of bytes printed
```

# Conversions
`%c` | single char             | `'A'` -> `A` ||| why we use int in ft_format not char bc we receive that from 'A' not "A" it will be int thats caller problems . and if size 
`%s` | string                  | `"hi"` -> `hi` 
`%p` | pointer address in hex  | `&x` -> `0x7ffee3a2b1c8`
`%d` | signed decimal          | `-42` -> `-42`
`%i` | signed integer          | `42` -> `42` you can use long to handle int nb = -nb
`%u` | unsigned decimal        | `-1` -> `4294967295`
`%x` | hex lowercase           | `255` -> `ff`
`%X` | hex uppercase           | `255` -> `FF`
`%%` | literal percent sign    | `%%` -> `%`

## Design Choices

- **No `malloc` at all**: every conversion is either a fixed literal (`(null)`, `(nil)`, `0x`, the sign) or written one byte at a time straight into `write()`. There's no `char *` buffer to build and free, so there's no leak surface to audit.
- **Recursion for digit printing** (`%d`/`%i`, `%u`, `%x`/`%X`, `%p`): printing decimal/hex digits naturally goes most-significant-digit-first, but `n % base` gives the least-significant digit first. Recursing on `n / base` before writing `n % base` prints digits in the correct order without needing a temporary buffer to reverse into.
- **`INT_MIN` special-cased as a literal** (`ft_putnbr_print.c`): negating `INT_MIN` is signed-integer-overflow undefined behavior, since `-INT_MIN` doesn't fit in an `int`. Comparing against the literal `-2147483648` up front and returning early avoids ever performing that negation.
- **Single `int total` accumulator, latched to `-1` on write failure** (`ft_out.c`): mirrors real `printf`'s contract — return the number of bytes written, or `-1` on error — without a separate error-flag variable. Once `total` goes negative, `ft_out` returns immediately without calling `write()` again, so one failed `write()` cleanly short-circuits the rest of the format string.
- **`va_list` passed by pointer between helpers**: `ft_printf` owns one `va_list` for the whole call; passing it by address to `ft_format` lets a single cursor advance through the arguments as the format string is walked, instead of copying the list (which would need `va_copy`).

## Resources

- [printf(3) — Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C variadic functions — cppreference](https://en.cppreference.com/w/c/variadic)
- [42 Norm documentation (Norminette)](https://github.com/42School/norminette)

### AI usage disclosure

Claude (via Claude Code) was used on this project for:

- **Auditing** the implementation against the 42 Norm and subject requirements: running `norminette` on every file, rebuilding with `-Wall -Wextra -Werror` to confirm a warning-free build, and checking the Makefile's incremental-rebuild behavior.
- **Cross-checking behavior against real `printf`**: writing and running comparison test cases (`INT_MIN`, `NULL` for `%s`/`%p`, `0`, empty format string, `%%`, back-to-back conversions, a trailing lone `%`) against glibc's `printf`/`snprintf` to verify matching output and return values.
- **Fixing two issues found during that audit**, both in `ft_printf.c`: a return-value mismatch on a trailing lone `%` at the end of the format string (now returns `-1` like real `printf`, instead of printing it literally and continuing), and removing a stray `main()` function that had been left in the file (which would have caused a "multiple definition of `main`" link error against any evaluator test file).
- **Writing** the "Design Choices" section above and this disclosure, based on reading the existing source files.

The `ft_printf` implementation itself — the parsing loop, per-conversion writer functions, and the recursive digit-printing approach — already existed in the repository before this audit; AI's role was limited to review, the two fixes listed above, and this README content.
