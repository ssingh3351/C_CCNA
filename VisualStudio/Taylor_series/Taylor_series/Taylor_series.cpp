// Taylor_series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//double e(int x, int n) {
//    static double P = 1, F = 1;
//    double r;
//    if (n == 0) {
//        return 1;
//    }
//    else {
//        r = e(x, n - 1);
//        P = P * x;
//        F = F * n;
//        return r + P / F;
//    }
//}

//double e(double x, double n) {
//    double s = 1;
//    for (; n > 0; n--) {
//        s = 1 + x / n * s;
//    }
//    return s;
//}

 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
