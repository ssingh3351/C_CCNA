// lower_traingular_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
// represenation of lower triangular matrix using row-major and column-major formulae

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct matrix {
    int* A;
    int n;
};

// ################ ROW-MAJOR #################################
//void set(struct matrix* m, int i, int j, int x) {
//    if (i >= j) {
//        m->a[i * (i - 1) / 2 + j - 1] = x;
//            
//    }
//}
//
//int get(struct matrix m, int i, int j) {
//    if (i >= j)
//        return m.a[i * (i - 1) / 2 + j - 1];
//    else
//        return 0;
//}
//
//void display(struct matrix m) {
//    int i, j;
//    for (i = 1; i <= m.n; i++) {
//        for (j = 1; j <= m.n; j++) {
//            if (i >= j)
//                printf("%d ", m.a[i * (i - 1) / 2 + j - 1]);
//            else
//                printf("0 ");
//        }
//        printf("\n");
//    }
//}

// ########################## COLUMN-MAJOR #######################
void set(struct matrix* m, int i, int j, int x) {
    if (i >= j) {
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;

    }
}

int get(struct matrix m, int i, int j) {
    if (i >= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void display(struct matrix m) {
    int i, j;
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            if (i >= j)
                printf("%d ", m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct matrix m;
    int i, j, x;

    printf("Enter the dimension of matrix:");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));
    
    printf("Enter all the elements:\n");
    for (i = 1; i <= m.n; i++) {
        for (j = 1; j <= m.n; j++) {
            scanf("%d", &x);
            set(&m, i, j, x);
        }
    }
    printf("\n\n");

    display(m);
    return 0;
}



