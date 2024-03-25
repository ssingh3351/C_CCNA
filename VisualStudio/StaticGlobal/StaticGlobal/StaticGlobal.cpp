// StaticGlobal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>

void fun(int n) {
    if (n > 0) {
        printf("%d", n);
        fun(n - 1);
    }
}
int main()
{
    fun(3);
    return 0;
}

