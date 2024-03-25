// Linked_list_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class linkedlist {
private:
    node* first;
public:
    linkedlist() {
        first = NULL;
    }
    linkedlist(int A[], int n);
    ~linkedlist();

    void display();
    void insert(int index, int x);
    int Delete(int index);
    int length();
    int binary_to_decimal();
};

linkedlist::linkedlist(int A[], int n) {
    node* last, * t;
    int i = 0;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
linkedlist::~linkedlist() {
    node* p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}
void linkedlist::display() {
    node* p = first;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int linkedlist::length() {
    node* p = first;
    int count = 0;
    while (p) {
        count += 1;
        p = p->next;
    }
    return count;
}
void linkedlist::insert(int index, int x) {
    node* t, * p = first;
    if (index<0 || index>length()) {
        return;
    }
    t = new node;
    t->data = x;
    t->next = NULL;
    if (index == 0) {
        t->next = first;
        first = t;
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int linkedlist::Delete(int index) {
    node* p, * q = NULL;
    int x = -1;
    if (index<0 || index>length()) {
        return -1;
    }
    if (index == 1) {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else {
        p = first;
        for (int i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int linkedlist::binary_to_decimal() {
    node* p = first;
    int res = 0;
    while (p != NULL) {
        res = (res << 1) + p->data;
        p = p->next;
    }
    return res;
}
int main()
{
    int A[] = { 1,1,0,0,1,0 };
    linkedlist l(A, 6);
    cout << "\nThe decimal equivalent of binary linked list is: " << l.binary_to_decimal();
    /*l.display();
    l.insert(0, 10);
    l.display();*/
    return 0;
}
