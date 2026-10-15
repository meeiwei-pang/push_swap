*This project has been created as part of the 42 curriculum by pmeei-we and ibishak*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers in ascending order using two stacks, Stack A and Stack B, and a limited set of stack operations.

The challenge is to find an efficient sequence of operations that sorts the input while minimizing the total number of instructions.

This project focuses on algorithm design, stack manipulation, operation costs, and optimization in C.

## Overview

The program takes a list of integers as arguments and outputs the operations required to sort them.

Initially, all integers are placed in Stack A, while Stack B is empty. The goal is to sort Stack A in ascending order and leave Stack B empty.

The available operations are:

| **Operation** | **Description** |
|---|---|
| `sa` | Swap the first two elements of Stack A |
| `sb` | Swap the first two elements of Stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element of Stack B onto Stack A |
| `pb` | Push the top element of Stack A onto Stack B |
| `ra` | Rotate Stack A upwards |
| `rb` | Rotate Stack B upwards |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate Stack A |
| `rrb` | Reverse rotate Stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

The program handles input validation, including invalid arguments, duplicate integers, and integer overflow, according to the project requirements.

## Sorting Algorithms

This implementation uses four sorting strategies depending on the number of elements to be sorted.

### Small Sort

Designed for a small number of elements. It uses carefully selected stack operations to sort the input with as few instructions as possible.

### Simple Sort — O(n²)

Uses a straightforward sorting approach for smaller inputs. The algorithm focuses on placing elements in the correct order while considering the cost of stack operations.

### Medium Sort — Chunk-Based Sorting

Designed for medium-sized inputs, this strategy divides the numbers into smaller groups called *chunks*.

Elements are pushed from Stack A to Stack B according to their chunk ranges. The elements are then pushed back to Stack A in the appropriate order.

Chunk-based sorting helps organize elements systematically and reduce unnecessary stack movements.

### Complex Sort

Designed for larger inputs, this strategy focuses on reducing the total number of operations through more advanced sorting decisions.

The algorithm considers the available elements and stack operations to determine an efficient sequence of moves.

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` executable at the root of the repository.

Other available rules:

```bash
make clean   # remove object files
make fclean  # remove object files and the executable
make re      # clean + full rebuild
```

### Usage

Run the program by passing a list of integers as arguments:

```bash
./push_swap 4 2 7 1 3
```

The program prints the sequence of operations required to sort the integers in ascending order.

Example:

```bash
./push_swap 3 2 1
```

The output consists of operations such as `sa`, `ra`, and `rra`, depending on the sorting strategy.

An already sorted input should not require any operations:

```bash
./push_swap 1 2 3 4 5
```

### Testing with the Checker

If a compatible `checker` executable is available, use it to verify the output.

```bash
ARG="4 2 7 1 3"
./push_swap $ARG | ./checker $ARG
```

A successful result should indicate that the stack is sorted correctly and Stack B is empty.

## Algorithm

The program begins by parsing and validating the input integers before initializing the stacks.

After initialization, it selects a sorting strategy based on the number of elements.

- **Small sort** handles small inputs using optimized operation sequences.
- **Simple sort** uses a straightforward approach for smaller inputs.
- **Medium sort** groups elements into chunks before transferring them between stacks.
- **Complex sort** uses a more advanced strategy to optimize the sorting process for larger inputs.

Each operation is evaluated in terms of its effect on the stack and its contribution to the total instruction count. The objective is to produce a correct sorting sequence while minimizing unnecessary operations.

## AI Usage

Claude (Anthropic) was used during the development of this project as a debugging and code review tool. AI assistance was mainly used to review existing code, identify potential logic and edge-case issues, explain sorting algorithms and operation costs, and help understand test results when evaluating the efficiency and correctness of different sorting strategies.

All code was written by the authors. AI was used for explanation, code review, and bug-spotting, and was not used to generate complete function implementations from the project subject.

## Resources

- The 42 `push_swap` subject PDF.
- Linux manual pages: `man 3 malloc`, `man 3 free`.
- C programming reference: [cppreference](https://en.cppreference.com/w/c.html).
- GNU Make manual: [https://www.gnu.org/software/make/manual/](https://www.gnu.org/software/make/manual/).