#include <iostream>
using namespace std;
double e(int x, int n) {
    static double P = 1, F = 1;
    double r;
    if (n == 0) {
        return 1;
    }
    else {
        r = e(x, n - 1);
        P = P * x;
        F = F * n;
        return r + P / F;
    }
}
int main()
{
    
    printf("%lf \n", e(1, 10));
    return 0;
}
