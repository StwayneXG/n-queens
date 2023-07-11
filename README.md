# n-Queens Problem

## Overview

In this project, we wrote a C program to solve the n-Queens problem.
The goal is to place n queens on a `n x n` chessboard such that no queen can attack another queen: no two queens can share the same row, column, or diagonal.

## Solution

There are multiple ways to solve this problem. The simplest one is to generate all possible configurations and check if they solve the problem.
However, this approach would require n^n configurations to be generated and checked, which is not feasible for large n.

Our project required using random board configurations and checking for n = `4, ..., 20`.

### Functions

The program is divided into 3 functions:

* `int check(int b[], int n)` returns 1 if the board solves the n-queens problem. Otherwise, it returns 0.
* `void displayBoard(int b[], int n)` displays the board configuration.
* `void randperm(int a[], int n)` generates a random permutation of the array a.

A pseudo-code of the algorithm is given below:

```
For i = n - 1 downto 1 do
    di <- random number in [0, i]
    swap(a[i], a[di])
```

## How to run

To run the program, run the following commands:

```
gcc -o nqueens nqueens.c
./nqueens
```

## License

This project is licensed under the MIT License - see the `LICENSE` file for details.
