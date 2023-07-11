#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INT_MAX 0x7FFFFFFF
#define STARTING_BOARD 4
#define ENDING_BOARD 20
#define TOTAL_BOARDS (ENDING_BOARD - STARTING_BOARD + 1)

int checkBoard(int b[], int n) {
    bool* column = (bool*)malloc(sizeof(bool) * n);
    bool* lr_diagonal = (bool*)malloc(sizeof(bool) * (2 * n - 1));
    bool* rl_diagonal = (bool*)malloc(sizeof(bool) * (2 * n - 1));

    memset(column, 0, sizeof(bool) * n);
    memset(rl_diagonal, 0, sizeof(bool) * (2 * n - 1));
    memset(lr_diagonal, 0, sizeof(bool) * (2 * n - 1));

    for (int i = 0; i < n; i++) {
        int diagonal_lr = i + b[i];
        int diagonal_rl = ((n - 1) - b[i]) + i;

        if (column[b[i]]) {
            free(column); free(lr_diagonal); free(rl_diagonal);
            return 0;
        }
        else {
            column[b[i]] = true;
        }

        if (lr_diagonal[diagonal_lr]) {
            free(column); free(lr_diagonal); free(rl_diagonal);
            return 0;
        }
        else {
            lr_diagonal[diagonal_lr] = true;
        }

        if (rl_diagonal[diagonal_rl]) {
            free(column); free(lr_diagonal); free(rl_diagonal);
            return 0;
        }
        else {
            rl_diagonal[diagonal_rl] = true;
        }
    }
    free(column); free(lr_diagonal); free(rl_diagonal);
    return 1;
}

void displayBoard(int b[], int n) {
    printf("\n[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("]\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i] == j)
                printf("*");
            else
                printf("-");
        }
        printf("\n");
    }
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void randperm(int a[], int n) {
    for (int i = n - 1; i > 0; i--) {
        long int k = rand() % i;
        swap(a[k], a[i]);
    }
}

long long pow(int a, int b) {
    long long out = 1;
    for (int i = 0; i < b; i++) {
        out *= a;
    }
    return out;
}

long long factorial(int n) {
    long long out = 1;
    for (int i = 1; i <= n; i++)
        out *= i;
    return out;
}

int main()
{
    srand(3975);

    long int minArr[TOTAL_BOARDS];
    for (int i = 0; i < TOTAL_BOARDS; i++) {
        minArr[i] = INT_MAX;
    }

    long int maxArr[TOTAL_BOARDS] = { 0 };
    double meanArr[TOTAL_BOARDS];


    for (int i = STARTING_BOARD; i <= ENDING_BOARD; i++) {

        int* board = (int*)malloc(sizeof(int) * i);

        long int sum = 0;
        for (int j = 0; j < 10; j++) {
            long int count = 0;

            do {
                for (int k = 0; k < i; k++)
                    board[k] = k;
                randperm(board, i);
                count++;
            } while (!checkBoard(board, i));

            if (j == 0) {
                displayBoard(board, i);
            }

            minArr[i - STARTING_BOARD] = (minArr[i - STARTING_BOARD] > count) ? count : minArr[i - STARTING_BOARD];
            maxArr[i - STARTING_BOARD] = (maxArr[i - STARTING_BOARD] < count) ? count : maxArr[i - STARTING_BOARD];
            sum += count;
        }
        meanArr[i - STARTING_BOARD] = sum / 10;
        free(board);

        printf("\n%5s%15s%15s%15s%20s%15s\n", "size", "min", "max", "mean", "size**size", "size!");
        printf("%5d%15ld%15ld%15f%20lld%15lld\n", i,
            minArr[i - STARTING_BOARD], maxArr[i - STARTING_BOARD],
            meanArr[i - STARTING_BOARD],
            pow(i, i),
            factorial(i));
    }
}
