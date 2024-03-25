// Circular_Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
using namespace std;
/*node creation*/
struct node {
    int data;
    struct node* next;
}*head;


/*creation of a linked list*/
void create(int A[], int n) {
    int i;
    struct node* t, * last;
    head = (struct node*)malloc(sizeof(node));
    head->data = A[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

/*Recursive display of linked list*/
void Rdisplay(struct node* h) {
    static int flag = 0;
    if (h != head || flag == 0) {
        flag = 1;
        printf("%d ", h->data);
        Rdisplay(h->next);
    }
    flag = 0;
}

/*Display of linked list*/
void display(struct node* h) {
    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}

/*calculating the length of a circular linked list */
int length(struct node* p) {
    int count = 0;
    do {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}


/*Inserting a new element in circular linked list */
void insert(struct node* p, int index, int x) {
    struct node* t;
    int i;
    if (index == 0) {
        t = (struct node*)malloc(sizeof(node));
        t->data = x;
        if (head == NULL) {
            head = t;
            head->next = head;
        }
        else {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    for (i = 0; i < index - 1; i++) p = p->next;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = p->next;
    p->next = t;

}

/*Function to delete a particular node from circular linked list */
int Delete(struct node* p, int index) {
    struct node* q;
    int i, x;
    if (index == 1) {
        while (p->next != head) p = p->next;
        x = head->data;
        if (p == head) {
            free(head);
            head = NULL;
        }
        else {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = { 2,3,4,5,6 };
    create(A, 5);
    display(head);
    Delete(head, 1);
    printf("\n");
    display(head);
}
