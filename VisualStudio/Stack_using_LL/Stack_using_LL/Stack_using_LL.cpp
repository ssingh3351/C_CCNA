// Stack_using_LL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;

struct Stack {
    int data;
    struct Stack* next;
}*top = NULL;

void push( int x) {
    struct Stack* t = (struct Stack*)malloc(sizeof(struct Stack));
    if (t == NULL)
        printf("\n Stack overflow!..");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop() {
    Stack* p;
    int x = -1;
    if (top == NULL) {
        printf("\n Stack is empty\n");
    }
    else {
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}
void display() {
    struct Stack* p;
    p = top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int stacktop(struct Stack *p) {
    if (top)
        return top->data;
    return -1;
}
int isempty(struct Stack p) {
    if (top == NULL)
        return 1;
    return 0;
}

int isfull() {
    struct Stack* t = (struct Stack*)malloc(sizeof(struct Stack));
    if (t == NULL)
        return 1;
    free(t);
    return 0;
}
int peek(int pos) {
    int x = -1;
    Stack* p = top;
    for (int i = 0; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p != NULL)
        x = p->data;
    return x;
}

int main() {
    push(10);
    push(20);
    push(300);

    display();
}
