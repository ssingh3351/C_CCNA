// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Stack {
    int size;
    int top;
    int* s;
};

void create(struct Stack* st) {
    printf("Enter the size of stack you want: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int*)malloc(st->size * sizeof(int));
}

void Display(struct Stack st) {
    int i = 0;
    for (i = st.top; i >= 0; i--) {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

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
    int x = -1;
    if ((st.top - position + 1) < 0) {
        printf("\n Posiiton is invalid\n");
    }
    else {
        x = st.s[st.top - position + 1];
    }
    return x;
}

int stacktop(struct Stack st) {
    if (st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

int isempty(struct Stack st) {
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isfull(struct Stack st) {
    if (st.top == st.size - 1)
        return 1;
    else
        return 0; 
}

int main()
{
    struct Stack stack1;
    create(&stack1);
    push(&stack1, 5);
    push(&stack1, 10);
    push(&stack1, 15);
    push(&stack1, 20);
    Display(stack1);
    printf("\n The popped element is : %d\n", pop(&stack1));
    Display(stack1);
    printf("\n The popped element is : %d\n", pop(&stack1));
    Display(stack1);
    
    //printf("Peeked element at %d position is:%d ", 4, peek(stack1, 4));

    return 0;
}
