// TailHead.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int fun(int n) {
    static int x = 0;
    if(n > 0) {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{
    int x = 5;
    printf("%d",fun(x));
    return 0;
}


