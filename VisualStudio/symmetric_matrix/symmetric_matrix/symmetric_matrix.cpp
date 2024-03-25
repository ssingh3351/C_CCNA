// symmetric_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
// MENU DRIVEN PROGRAM FOR DIAGONAL MATRIX

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int* A, n, ch, x, i, j;
    printf("Enter dimensions of array: ");
    scanf("%d", &n);
    A = (int*)malloc(n * sizeof(int));

    do {
        printf("Display menu:\n 1. create\n 2. get\n 3. Set\n 4. Display\n Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            for (i = 1; i <= n; i++)
                scanf("%d",& A[i - 1]);
            break;
        case 2:
            printf("Enter indices: ");
            scanf("%d %d", &i, &j);
            if (i == j)
                printf("%d", A[i - 1]);
            else
                printf("0");
            break;
        case 3:
            printf("Enter row col details:");
            scanf("%d %d %d", &i, &j, &x);
            if (i == j)
                A[i - 1] = x;
            break;
        case 4:
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (i == j)
                        printf("%d", A[i - 1]);
                    else
                        printf("0");
                }
                printf("\n");
            }
            break;
        }
    } while (ch > 0 && ch <= 4);
}
