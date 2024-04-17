// Paranthesis_Matching_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;

struct Stack {
    char data;
    struct Stack* next;
}*top = NULL;

void push(char x) {
    struct Stack* t = (struct Stack*)malloc(sizeof(struct Stack));
    if (t == NULL)
        printf("\n Stack overflow!..");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop() {
    Stack* p;
    char x = -1;
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
int isempty() {
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

int stacktop() {
    if (top != NULL) {
        return top->data;
    }
    return -1;
}
int isBalanced(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (isempty()) {
                return false;
            }
            char x = stacktop();
            if ((x == '(' && exp[i] == ')') || (x == '[' && exp[i] == ']') || (x == '{' && exp[i] == '}')) {
                pop();
            }
            else
                return false;
        }
    }
    if (isempty()) {
        return true;
    }
    return false;
}
int main() {
    char exp[] = "{([a+b]*[c-d])/e}";
    printf("%d ", isBalanced(exp));
}
