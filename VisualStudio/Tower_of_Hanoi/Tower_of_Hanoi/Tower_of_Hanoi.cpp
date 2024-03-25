// Tower_of_Hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//void TOH(int n, int A, int B, int C) {
//    if (n > 0) {
//        TOH(n - 1, A, C, B);
//        printf("(%d, %d)\n", A, C);
//        TOH(n - 1, B, A, C);
//    }
//}
//int f(int n)
//
//{
//
//    static int i = 1;
//
//    if (n >= 5)
//        return n;
//
//    n = n + i;
//
//    i++;
//
//    return f(n);
//
//}
//
//int main()
//{
//    //TOH(5, 1, 2, 3);
//    printf("%d ", f(1));
//    return 0;
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





//void foo(int n, int sum)
//
//{
//
//    int k = 0, j = 0;
//
//    if (n == 0) return;
//
//    k = n % 10;
//
//    j = n / 10;
//
//    sum = sum + k;
//
//    foo(j, sum);
//
//    printf("%d", k);
//
//}
//
//int main()
//
//{
//
//    int a = 2048, sum = 0;
//
//    foo(a, sum);
//
//    printf("%d\n", sum);
//
//}

void count(int n)
{
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if (n > 1) count(n - 1);
    printf("%d", d);
}

int main() {
    count(3);
    return 0;
}