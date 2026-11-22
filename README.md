*This project has been created as part of the 42 curriculum by pnanna.*

# ft_printf

## Description

This project implements the mandatory conversions of printf in C. The function
`ft_printf(const char *format, ...)` writes to standard output and returns the
number of bytes written, or -1 if a write fails. It handles characters (%c),
strings (%s), pointers (%p), signed decimal integers (%d and %i), unsigned
decimal integers (%u), hexadecimal integers (%x and %X), and a literal percent
sign (%%).

## Instructions

Run `make` in the project directory to create `libftprintf.a`. To try the
library, save the following program as `example.c` next to the Makefile.

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("hex=%X\n", 42u);
    ft_printf("count=%d\n", count);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror example.c libftprintf.a -o example
./example
```

The program prints `hex=2A` and then `count=7`. The newline counts as one byte.
Use `make clean` to remove object files, `make fclean` to also remove the
library, and `make re` to rebuild it.

## Algorithm and data structures

The parser walks the format string once with a pointer. It writes ordinary
characters immediately. When it sees a percent sign, it advances to the
conversion character and dispatches to the matching helper. A single va_list
tracks the next argument. Passing its address lets each conversion advance the
same list, while %% consumes no argument. The parser adds each helper's return
value to its count and stops on the first write error. It needs neither a heap
allocation nor an output buffer.

The number helpers share a digit string and a base. Integer division by the
base removes the last digit. Recursion prints the remaining digits first, then
the remainder selects the last character from the digit string. For example,
423 / 10 yields 42, and 423 % 10 selects '3'. The same algorithm works for
hexadecimal when the base is 16. Choosing the lowercase or uppercase digit
string controls the case. The call stack uses one frame per digit.

For a negative int, the signed helper widens the value to long long before
negating it so that INT_MIN can be printed on the target Linux system. For a
non-null pointer, the pointer helper prints 0x and converts the address to
uintptr_t before formatting its hexadecimal digits. The null pointer spelling
used here is (nil).

## Resources

- Linux manual pages: `man 3 printf` for conversions and return values,
  `man 3 stdarg` for variadic arguments, and `man 2 write` for output errors.
- The 42 ft_printf subject, version 12.1, defines the mandatory deliverables.
- AI assisted with understanding numeric conversion and error propagation,
  reviewing the implementation against the subject, organizing the source
  files, testing output and return values, and drafting this README.
