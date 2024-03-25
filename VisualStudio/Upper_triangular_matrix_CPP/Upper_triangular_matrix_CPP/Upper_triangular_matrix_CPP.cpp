// UPPER TRIANGULAR MATRIX 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class matrix {
private:
    int* A;
    int n;
public:
    matrix() {
        n = 5;
        A = new int[2 * (2 + 1) / 2];
    }
    matrix(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~matrix() {
        delete[]A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};
// ################# COLUMN-MAJOR ####################


void matrix::set(int i, int j, int x) {
    if (i <= j) {
        A[j * (j - 1) / 2 + i - 1] = x;
    }
}

int matrix::get(int i, int j) {
    if (i <= j)
        return A[j * (j - 1) / 2 + i - 1];
    else
        return 0;
}

void matrix::display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i <= j)
                cout << A[j * (j - 1) / 2 + i - 1]<<" ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

//####################### ROW-MAJOR ##########################

/*
void matrix::set(int i, int j, int x) {
    if (i <= j) {
        A[n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i] = x;
    }
}

int matrix::get(int i, int j) {
    if (i <= j)
        return A[n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i];
    else
        return 0;
}

void matrix::display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
*/
int main()
{
    int d;
    cout << "Enter dimensions of matrix: ";
    cin >> d;
    matrix m(d);

    int x;
    cout << "Enter all elements";
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> x;
            m.set(i, j, x);
        }
    }

    m.display();

}
