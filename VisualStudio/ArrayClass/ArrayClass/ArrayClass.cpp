// ArrayClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
// We are making this program as generic to take values of any kind.


#include <iostream>
using namespace std;

template<class T>
class Array {
private:
    T* A;
    int size;
    int length;
public:
    Array() {  //non-parameterized constructor
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz) {  // paratemetrizecd constructor
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array() {  // destructor
        delete[]A;
    }
    void Display();
    void insert(int index, T x);
    T Delete(int index);
};

template <class T>
void Array<T>::Display() {
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template<class T>
void Array<T>::insert(int index,T x) {
    if (index >= 0 && index <= length) {
        for (int i = length - 1; i >= index; i--) {
            A[i + 1] = A[i];
         }
        A[index] = x;
        length++;
    }
}
template<class T>
T Array<T>::Delete(int index) {
    int x = 0;
    if (index >= 0 && index < length) {
        x = A[index];
        for (int i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

int main()
{
    Array<int> arr(10);

    arr.insert(0, 5);
    arr.insert(1, 6);
    arr.insert(2, 9);
    arr.Display();
    cout << arr.Delete(1)<<endl;
    arr.Display();
}
