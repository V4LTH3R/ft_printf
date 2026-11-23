 <div align="center">

# ft_printf

This repository contains my implementation of **ft_printf**, a project from the **42 Common Core (1337)**. The goal is to recreate the behavior of the standard C library function `printf`, handling formatted output, variadic arguments, and multiple conversion specifiers.

---

## What is ft_printf?

**ft_printf** is a project where you recode the standard C library function `printf` from scratch.

The main objective is to understand how variadic functions work in C and how formatted output is processed internally.

- No use of the original `printf` function.
- Only the permitted external functions from the project subject.
- Strict compliance with the **42 Norm**.
- Compiled into a static library (`libftprintf.a`) using a custom **Makefile**.

Focus areas:

**Variadic Functions (`va_list`, `va_start`, `va_arg`, `va_end`)**  
**Algorithms & Data Structures**  
**Formatted Output & Conversion Specifiers**  
**Data Types & Type Casting**  
**File Descriptors & `write()`**  
**Return Values & Error Handling**

---

## Subject & Resources

All official project requirements and subject PDFs are available here:

[`ftprintf Subject`](https://github.com/V4LTH3R/ft_printf/blob/main/ftprintf.en.subject.pdf)

Includes:

- Mandatory Part – Reimplementation of `printf`.
- Conversion specifiers and formatting rules.
- Variadic arguments management.
- Makefile & Norminette rules.

---

## Progress Tracker – Overview

| Category | Status | Count | Topics |
| :--- | :---: | :---: | :--- |
| **1. Character Conversion** | ✅ | **1** | `%c` |
| **2. String Conversion** | ✅ | **1** | `%s` |
| **3. Pointer Conversion** | ✅ | **1** | `%p` |
| **4. Integer Conversions** | ✅ | **3** | `%d`, `%i`, `%u` |
| **5. Hexadecimal Conversion** | ✅ | **2** | `%x`, `%X` |
| **6. Percentage Conversion** | ✅ | **1** | `%%` |
| **7. Format String Parsing** | ✅ | — | Sequential parsing & specifier detection |
| **8. Number Conversion Algorithms** | ✅ | — | Decimal & hexadecimal conversion |
| **9. Variadic Arguments** | ✅ | — | `va_list`, `va_start`, `va_arg`, `va_end` |
| **10. Data Structures** | ✅ | — | Format strings, argument handling & counters |
| **Build System** | ✅ | — | `Makefile` & `ft_printf.h` (`libftprintf.a`) |

---

## Library Contents

ft_printf reimplements the standard `printf` function with the following conversion specifiers.

### 1. Character Conversion

*Handles individual character output.*

| Specifier | Description |
| :--- | :--- |
| `%c` | Prints a single character. |

### 2. String Conversion

*Handles string output.*

| Specifier | Description |
| :--- | :--- |
| `%s` | Prints a string of characters. Handles `NULL` according to the project's required behavior. |

### 3. Pointer Conversion

*Handles memory address representation.*

| Specifier | Description |
| :--- | :--- |
| `%p` | Prints a pointer address in hexadecimal format, prefixed with `0x`. |

### 4. Integer Conversions

*Handles signed and unsigned decimal numbers.*

| Specifier | Description |
| :--- | :--- |
| `%d` | Prints a signed decimal integer. |
| `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |

### 5. Hexadecimal Conversion

*Handles hexadecimal number representation.*

| Specifier | Description |
| :--- | :--- |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |

### 6. Percentage Conversion

*Handles literal percentage characters.*

| Specifier | Description |
| :--- | :--- |
| `%%` | Prints a literal `%` character without consuming a variadic argument. |

---

## Algorithms & Data Structures

The project involves designing algorithms to process format strings, retrieve variadic arguments, convert values, and produce formatted output efficiently.

### 1. Format String Parsing

*Scans the format string character by character to identify literal characters and conversion specifiers.*

| Algorithm | Description |
| :--- | :--- |
| Sequential Parsing | Iterates through the format string using an index. |
| Specifier Detection | Identifies conversion specifiers after encountering `%`. |
| Dispatching | Routes each specifier to its corresponding conversion function. |

### 2. Number Conversion Algorithms

*Converts numeric values into their corresponding character representations.*

| Algorithm | Description |
| :--- | :--- |
| Decimal Conversion | Extracts digits using division and modulo operations. |
| Unsigned Conversion | Handles unsigned integers without signed-value assumptions. |
| Hexadecimal Conversion | Converts numbers using base 16. |
| Pointer Conversion | Represents memory addresses in hexadecimal format. |
| Recursive or Iterative Output | Produces digits in the correct order. |

### 3. Data Structures

*Uses C language structures and types to manage format processing and variadic arguments.*

| Data Structure | Description |
| :--- | :--- |
| `va_list` | Manages access to the variable arguments passed to the function. |
| `const char *format` | Stores the format string being processed. |
| Integer Counters | Track the number of characters successfully written. |
| Function Pointers (if used) | Associate conversion specifiers with their corresponding handlers. |

### 4. Output Management

*Manages character output and return values.*

| Concept | Description |
| :--- | :--- |
| `write()` | Writes characters directly to a specified file descriptor. |
| Return Counter | Tracks the number of characters successfully written. |
| Error Handling | Handles output failures and propagates error return values. |
| Type Casting | Converts values into the appropriate types for output. |

### 5. Algorithmic Complexity

| Operation | Time Complexity |
| :--- | :--- |
| Format String Parsing | O(n) |
| Character Output | O(1) per character |
| Decimal Conversion | O(d) |
| Hexadecimal Conversion | O(h) |
| Complete Format Processing | O(n + k) |

Where:

- `n` = length of the format string.
- `d` = number of decimal digits.
- `h` = number of hexadecimal digits.
- `k` = total number of characters generated by conversions.

---

## Variadic Arguments

One of the main concepts behind this project is the use of variadic functions.

Variadic functions are functions that accept a variable number of arguments.

The following macros are used to manage these arguments:

| Macro | Description |
| :--- | :--- |
| `va_list` | Declares a variable used to access variadic arguments. |
| `va_start` | Initializes access to the variadic arguments. |
| `va_arg` | Retrieves the next argument with the requested type. |
| `va_end` | Ends the access to variadic arguments. |

Example:

```c
int ft_printf(const char *format, ...);
```

The function processes the format string, identifies conversion specifiers, retrieves the corresponding arguments, and prints the formatted output.

---

## Usage & Compilation

To compile the library, clone the repository and run `make`:

```bash
git clone YOUR_REPOSITORY_URL
```

```bash
cd ft_printf
```

```bash
make
```

To use it in your own C projects, include the header and link `libftprintf.a`:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```

---

## Testing & Evaluation

Before submitting to Moulinette, make sure to test different conversion specifiers, edge cases, and return values.

Important test cases:

- Empty format strings.
- `NULL` string pointers.
- `INT_MIN` and `INT_MAX`.
- `UINT_MAX`.
- `NULL` pointers with `%p`.
- Multiple conversion specifiers in one format string.
- Mixed literal text and conversions.
- Correct number of characters returned.
- Output failures and invalid file descriptors.
- Unsupported format specifiers, according to the project subject.

**Norminette**: `norminette`

**Popular Testers**:

- [`printfTester`](https://github.com/Tripouille/printfTester)
- [`printf_tester`](https://github.com/Sfabi28/printf_tester)

> Focus on understanding variadic arguments, memory representation, integer conversions, algorithmic complexity, and the behavior of `write()`, not just passing testers.

---

## Important

> Do not copy solutions directly.  
> Understand how `printf` processes each conversion specifier.  
> Learn how variadic arguments are retrieved and how different C data types are represented in memory.  
> Understand the algorithms behind number conversion and format parsing.  
> Test edge cases and compare your implementation against the original `printf`.

For any questions: Discord username **metaplasticity**

<p align="center">
<img src="https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white">
</p>

</div>
