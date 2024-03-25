// Lower_triangular_matrix_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// lower matrix implementation using C++ class, it used both row-major and colunmn-major methods
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
        A = new int[2*(2+1)/2];
    }
    matrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    ~matrix(){
        delete []A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};
// ################# ROW-MAJOR ####################

/*
void matrix::set(int i, int j, int x) {
    if (i >= j) {
        A[i * (i - 1) / 2 + j - 1] = x;
    }
}

int matrix::get(int i, int j) {
    if (i <= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void matrix::display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[i * (i - 1) / 2 + j - 1]<<" ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}*/

//####################### COLUMN-MAJOR ##########################
void matrix::set(int i, int j, int x) {
    if (i >= j) {
        A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
    }
}

int matrix::get(int i, int j) {
    if (i <= j)
        return A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void matrix::display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i >= j)
                cout << A[n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

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
