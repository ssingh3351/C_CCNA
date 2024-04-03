// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;

struct Stack {
    int size;
    int top;
    int* s;
};

void push(Stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("\nStack overflow\n");
    }
    else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack* st) {
    int x = -1;
    if (st->top == -1) {
        printf("\n Stack Underflow\n");
    }
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int position) {
    
}

int main()
{
    struct Stack st;
    printf("Enter the size of stack you want: ");
    scanf("%d", &st.size);

    st.s = (int*)malloc(st.size * sizeof(int));
    st.top = -1;

    return 0;
}
