// Dynamic_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

//int main()
//{
//    int A[5] = {2,4,6,8,10};
//    int* p;
//    int i;
//
//    p = (int*)malloc(5 * sizeof(int));
//    p[0] = 3;
//    p[1] = 5;
//    p[2] = 7;
//    p[3] = 9;
//    p[4] = 11;
//
//    for (i = 0; i < 5; i++)
//        printf("%d ", A[i]);
//
//    printf("\n");
//    for (i = 0; i < 5; i++)
//        printf("%d ", p[i]);
//    return 0;
//}

/*
How to increase the size of array
*/

int main() {
	int *p, *q;
    int i;
	p = (int*)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    q = (int*)malloc(10 * sizeof(int));

    for (i = 0; i < 5; i++) {
        q[i] = p[i];
    }
    free(p);
    p = q;
    q = NULL;

    for (i = 0; i < 5; i++) {
        printf("%d ", q[i]);
    }
	return 0;
}