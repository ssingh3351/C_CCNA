// Paranthesis_Matching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct Stack {
    int size;
    int top;
    char* s;
};
void push(Stack* st, char x) {
    if(st->top == st->size-1){
        printf("\nStack overflow\n");
    }
    else {
        st->top++;
        st->s[st->top] = x;
    }
}
char pop(struct Stack* st) {
    char x;
    if (st->top == -1) {
        printf("\n Stack Underflow\n");
    }
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}


int isempty(struct Stack st) {
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isBalance(char* exp) {
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = new char[st.size];

    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')') {
            if (isempty(st)) return false;
            pop(&st);
        }
    }
    return isempty(st) ? true : false;
}

int main() {
    char exp[] = "((a+b)*(a-b))";
    printf("%d", isBalance(exp));
    return 0;
}