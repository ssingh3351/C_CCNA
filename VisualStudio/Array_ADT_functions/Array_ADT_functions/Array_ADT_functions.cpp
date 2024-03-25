#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct  Array {
    //int A[10];
    int* A;
    int size;
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("\nElements are \n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;

}

void Insert(struct Array* arr, int index, int x) {
    int i;
    if (index >= 0 && index <= arr->length) {
        for (i = arr->length; i > index; i--) {
            arr -> A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr,  int index) {
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length) {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            swap(&arr->A[i], &arr->A[0]);
            return i ;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid]) {
            return RBinarySearch(arr, l, mid - 1, key);
        }
        else
            return RBinarySearch(arr, mid + 1, h, key);
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array* arr, int index, int value) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = value;
    }
}

void Reverse(struct Array* arr) {
    int i;
    for (i = 0; i < arr->length / 2; i++) {
        int temp;
        temp = arr->A[i];
        arr->A[i] = arr->A[arr->length-1 - i];
        arr->A[arr->length-1 -i] = temp;
    }
}


void InsertinSorted(struct Array* arr, int key) {
    int i;
    for (i = arr->length-1; arr->A[i]> key; i--) {
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[i+1] = key;
    arr -> length++;    
}

bool Ifsorted(struct Array arr) {
    int i;
    for (i = 0; i < arr.length-1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return false;
        }
    }
    return true;
}

void positive_negative(struct Array* arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] > 0)
            j--;
        if (i<j)
            swap(arr->A[i], arr->A[j]);
    }
}

struct Array* merge(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}

int main()
{
    struct Array arr = { {2,-3,6,-5,7,-8}, 10, 6 };
    struct Array arr1 = { {2,6,10,15,25},10,5 };
    struct Array arr2 = { {3,6,7,15,20},10,5 };
    struct Array* arr3; // for storing the merged array
    //struct Array arr;
   /* int n, i; */// for asking how many numbers we want to enter and the taking them as input
    /*printf("Enyter size of an array: ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter the count of numbers you want to enter: ");
    scanf("%d", &n);

    printf("\nEnter all elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;*/

    
    //printf("The key is found at %d index\n", RBinarySearch(arr,0, 4,3));
    Display(arr1);
    printf("\n");
    Display(arr2);
    //Set(&arr, 3, 7);
    /*Reverse(&arr);*/
    //InsertinSorted(&arr, 4);
    //printf("%i\n", Ifsorted(arr));
    //positive_negative(&arr);

    arr3 = Difference(&arr1, &arr2);
    printf("\nafter Difference the result is : \n");
    Display(*arr3);



    return 0;



}