// Doubly_Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
using namespace std;

struct node {
	struct node* prev;
	int data;
	struct node* next;
}*first = NULL;

void create(int A[], int n) {
	struct node* t, *last;
	int i;

	first = (struct node*)malloc(sizeof(struct node));
	first->data = A[0];
	first->prev = first->next = NULL;
	last = first;

	for (i = 1; i < n; i++) {
		t = (struct node*)malloc(sizeof(struct node));
		t->data = A[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}

void Display(struct node* p) {
	while (p != NULL) {
		printf("%d ", p->data);
			p = p->next;
	}
	printf("\n");
}

int Length(struct node* p) {
	int len = 0;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}

void Insert(struct node* p, int index, int x) {
	struct node* t;
	if (index < 0 || index > Length(p))
		return;
	if (index == 0) { /* If we are inserting on the first place*/
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	/*If we are inserting after a certain node */
	else {
		int i = 0;
		while (i < index-1) {
			p = p->next;
			i++;
		}
		t = (struct node*)malloc(sizeof(struct node));
		t->data = x;
		t->next = p->next;
		t->prev = p;
		if(p->next)
			p->next->prev = t;
		p->next = t;
	}
}

int Delete(struct node* p, int index) {
	struct node* q;
	int x = -1, i;
	if (index<1 || index>Length(p)) {
		return -1;
	}
	if (index == 1) { /*deleting first node*/
		first = first->next;
		if (first) first->prev = NULL;

		x = p->data;
		free(p);
	}
	else { /*deleting other nodes*/
		for (i = 0; i < index - 1; i++) {
			p = p->next;
		}
		p->prev->next = p->next;
		if (p->next) p->next->prev = p->prev; /*check if the node to be deleted is the last node*/
		x = p->data;
		free(p);
	}

	return x;
}

void Reverse(struct node* p) {
	struct node* temp;
	while (p) {
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p!=NULL && p->next == NULL)
			first = p;
	}
}

int main()
{
	int A[] = { 10,20,30,40 };
	create(A, 4);
	printf("\n");
	
	Display(first);

	/*Insert(first, 0, 50);
	printf("\nAfter inserting\n");

	Display(first);
	printf("\n Deleting\n");

	Delete(first, 1);*/
	Reverse(first);

	Display(first);

	return 0;
}
