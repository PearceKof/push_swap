# Push_swap
![42](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)

Push_swap is a sorting algorithm project implemented in C as part of a curriculum at 19 (42 Network). The goal is to sort a list of integers using two stacks, minimizing the number of operations performed.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Operations](#operations)
- [Validation](#validation)
- [Bonus](#bonus)

## Project Overview

The Push_swap project aims to enhance our understanding of sorting algorithms, stack management, and performance optimization in C. The program sorts integers placed in stack `a`, utilizing stack `b` as an auxiliary.

## Features

- Sorts integers in ascending order using two stacks
- Minimizes the number of operations to achieve sorting
- Provides error handling for invalid input
- Complies with project norms and guidelines

## Requirements

- All requirements for this project are outlined in the project description.
- Language: C, following the Norm.
- Memory Management: All allocated memory must be properly freed, and no memory leaks are tolerated.
- Makefile: The project must include a Makefile with at least the following rules: all, clean, fclean, re, and $(NAME).
- Compilation: Use `gcc` with the flags `-Wall`, `-Wextra`, and `-Werror`.
- Libft: The use of your own libft is authorized if it is included in the project directory.

## Installation

To build and run Push_swap, you need a C compiler and `make`. This program is compatible with Unix-like systems.

1. Clone the repository:
```
git clone https://github.com/yourusername/push_swap.git
```
2. Go to the cloned repository
```
cd push_swap
```

3. Build the project:
```
make
```

4. The Makefile includes the following targets:
- `all`: Compiles the project
- `clean`: Removes object files
- `fclean`: Removes object files and the executable
- `re`: Rebuilds the project

## Usage

After building the project, you can start it by running:
```
./push_swap 2 1 3 6 5 8
```
This will output the smallest list of operations needed to sort the numbers.

There is a checker that check if the final result is indeed sorted or not. You can use it like this:
- Linux:
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```
- macOS:
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

## Operations

Push_swap supports the following operations:

- `sa`: Swap the first two elements of stack `a`.
- `sb`: Swap the first two elements of stack `b`.
- `ss`: `sa` and `sb` at the same time.
- `pa`: Push the first element of `b` onto `a`.
- `pb`: Push the first element of `a` onto `b`.
- `ra`: Rotate stack `a` upwards.
- `rb`: Rotate stack `b` upwards.
- `rr`: `ra` and `rb` at the same time.
- `rra`: Rotate stack `a` downwards.
- `rrb`: Rotate stack `b` downwards.
- `rrr`: `rra` and `rrb` at the same time.

## Bonus

As a bonus for the project, it is proposed to recreate the checker that verifies whether the instructions generated by `push_swap` properly sort the stack.
