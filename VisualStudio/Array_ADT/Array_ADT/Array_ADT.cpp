// Array_ADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS // to remove the error of scanf_s
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct  Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("\nElemnets are \n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array arr;
    int n, i; // for asking how many numbers we want to enter and the taking them as input
    printf("Enyter size of an array: ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter the count of numbers you want to enter: ");
    scanf("%d", &n);
    
    printf("\nEnter all elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;

    Display(arr);



    return 0;
    


}