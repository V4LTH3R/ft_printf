*This project has been created as part of the 42 curriculum by v4lth3r*

## Description
**ft_printf** is a project at 42 School where the goal is to recreate the standard C library function `printf`. 

The main objective is to learn how variadic functions work in C (functions that accept a changing number of arguments) and to build a clean, modular, and well-structured codebase that can be reused in future 42 projects.

This implementation handles the following conversions:
* `%c`: Prints a single character.
* `%s`: Prints a string.
* `%p`: Prints a pointer address in hexadecimal format.
* `%d` / `%i`: Prints a signed decimal integer.
* `%u`: Prints an unsigned decimal integer.
* `%x` / `%X`: Prints a number in lowercase or uppercase hexadecimal format.
* `%%`: Prints a literal percent sign.

## Instructions

### Compilation

before making library and start use it u should clone repo by follwing this command

```bash
git clone <repo/url>
cd printf
```

To compile the library, run `make` at the root of the repository. This will generate the static library file `libftprintf.a`.

```bash
make all clean
```

Other available Makefile rules:
* `make clean`: Removes object files (`.o`).
* `make fclean`: Removes object files and the `libftprintf.a` library.
* `make re`: Recompiles the entire project from scratch.

### Usage
To use `ft_printf` in your own C program, include the header file in your code and link the compiled library during compilation:

1. Include the header in your C file:
```c
#include "ft_printf.h"
```

2. Compile your program with `libftprintf.a`:
```bash
cc main.c libftprintf.a -o program
./program
```

## Resources

### Classic References
* [Linux Manual Page: printf(3), stdarg(3)](https://man7.org/linux/man-pages/printf)
* [GeeksforGeeks: Variadic Functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

### AI Usage
AI was used to learn more about variadic fucntion in c, ask questions, clear doubts, and better understand different concepts.

## Algorithm and Data Structure

The project uses a simple and organized algorithm to reproduce the behavior of the original `printf()` function.

The algorithm reads the format string character by character. When it finds a normal character, it prints it directly. When it finds a `%` symbol, it checks the next character to identify the required conversion and calls the corresponding function.

### Algorithm
1. Read the format string character by character.
2. Check if the current character is a normal character or a `%` symbol.
3. If it is a normal character, print it using `write()`.
4. If it is `%`, identify the conversion specifier.
5. Retrieve the corresponding argument using `va_arg`.
6. Call the appropriate function to handle the conversion.
7. Count the total number of characters printed.
8. Return the final character count.

### Data Structures
The project uses:
- **`va_list`**: To handle the variable number of arguments.
- **Pointers**: To navigate through the format string and access string arguments.
- **Functions**: To separate each conversion and keep the code modular.
- **Integer counters**: To track the number of characters printed.

### Why This Approach?

This approach makes the code easier to read, understand, and maintain. Using separate functions for each conversion avoids repeating code and makes it easier to add or modify features.

It also follows the same basic idea as the original `printf()` function while keeping the implementation simple and efficient.