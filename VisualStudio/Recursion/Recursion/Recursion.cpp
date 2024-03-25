// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;

//int fun(int n) {
//    if (n > 100)
//        return n - 10;
//    else
//        return fun(fun(n + 11));
//}

int exp(int m, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return pow(m * m, n / 2);
    }
    else {
        return m * pow(m * m, (n - 1) / 2);
    }
}

int main()
{
    printf("%d", exp(2,5));
    return 0;
}

