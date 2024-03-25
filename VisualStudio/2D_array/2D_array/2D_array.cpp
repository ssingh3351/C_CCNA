// 2D_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

////normal declaration of a 2D array 
//int main()
//{
//    int a[3][4] = { {1,2,3,4},{2,4,6,8},{3,5,7,9} };
//    return 0;
//}
//
////Array of pointers method of creating a 2D array.
//
//int main() {
//    int* a[3]; // this array will be present in the stack
//    a[0] = new int[4];// this will be stored in heap
//    a[1] = new int[4];// this will be stored in heap
//    a[2] = new int[4];// this will be stored in heap
//    return 0;
//}

// method - 3: using double pointer

int  main() {
	/*int** a;
	a = new int* [3];
	a[0] = new int[4];
	a[1] = new int[4];
	a[2] = new int[4];*/
	unsigned int x[4][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };
	printf("%u, %u, %u", x + 3, *(x + 3), *(x + 2) + 3);
	return 0;
}