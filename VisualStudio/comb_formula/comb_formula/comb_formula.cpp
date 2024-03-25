// comb_formula.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//int fact(int n) {
//    if (n == 0)
//        return 1;
//    else {
//        return n * fact(n - 1);
//    }
//}

//int C(int n, int r) {
//    int t1, t2, t3;
//    t1 = fact(n);
//    t2 = fact(r);
//    t3 = fact(n - r);
//
//    return t1 / (t2 * t3);
//}

int C(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    else {
        return C(n - 1, r - 1) + C(n - 1, r);
    }
}

int main()
{
    printf("%d", C(5, 3));
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
