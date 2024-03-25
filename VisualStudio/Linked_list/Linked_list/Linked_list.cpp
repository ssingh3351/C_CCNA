// Linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Linked List creation and display
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>

using namespace std;

struct node {
    int data;
    struct node* next;
}*first = NULL, * second = NULL, * third = NULL;

void create(int A[], int n) {
    int i;
    struct node* t, * last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n) {
    int i;
    struct node* t, * last;
    second = (struct node*)malloc(sizeof(struct node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//void display(struct node* p) {
//    while (p != null) {
//        printf("%d ", p->data);
//        p = p->next
//    }
//}

/* Recursive display of elements of a linked list */
void display(struct node* p) {
    if (p != NULL) {
        printf("%d ", p->data);
        display(p->next);
    }
}

//int count(struct node* p) {
//    int count = 0;
//    while (p != NULL) {
//        count += 1;
//        p = p->next;
//    }
//    return count;
//}

/* Recursive function for counting the nodes in linked list */
int count(struct node* p) {
    if (p == NULL)
        return 0;
    else
        return 1 + count(p->next);
}


/* function to find the sum of all elements of a linked list*/
int sum(struct node* p) {
    int sum = 0;

    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int max1(struct node* p) {
    int m = INT32_MIN;
    while (p) {
        if (p->data > m) {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}
/*function for linear search */
node* search(struct node* p, int key) {
    while (p) {
        if (key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

/*imporved function with move to head implemented for liner search*/
node* search1(struct node* p, int key) {
    struct node* q = NULL;
    while (p) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

/* function to insert an element in linked list */
void insert(struct node* p, int index, int x) {
    struct node* t;
    int i;
    // checking if the index enetered is correct or not 
    if (index<0 || index>count(p)) {
        return;
    }
    t = (struct node*)malloc(sizeof(node));
    t->data = x;
    
    // if the index entered is 0
    if (index == 0) {
        t->next = first;
        first = t;
    }
    // if the index entered is other than 0
    else {
        for (i = 0; i < index - 1; i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    
}

/* Function to dete a node from linked list */

int Delete(struct node* p, int index) {
    struct node* q = NULL;
    int x = -1,i;
    if (index<1 || index>count(p)) // check if the index entered is valid or not
        return -1;
    if (index == 1) { // if first noe neds to be deleted
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    // if other nodes at specific index needs to be deleted
    else {
        for (i = 0; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }

}

/* function to check if the linked list is sorted or not */
bool Is_sorted(struct node* p) {
    int x = INT32_MIN;
    while (p != NULL) {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

/* function to rempve duplicates from the linked list */
void rduplicate(struct node* p) {
    // we have to take one more pointer pointing to the next element
    struct node* q = p->next;
    // iterate q till null and check if p->data is equal to q->data
    while (q != NULL) {
        // if p and q data are not same, increase both
        if (q->data != p->data) {
            p = q;
            q = q->next;
        }
        // if the data is equal in both, then perform the below steps
        else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

/* function to reverse the elements in linked list by reversing the elements method */
void reverse_elements(struct node* p) {
    // first we are taking an array dynamically to store the elements of linked list
    int* A; 
    A = (int*)malloc(count(first) * sizeof(int));
    int i = 0;
    // copying all the elements of linked list to A
    while (p != NULL) {
        A[i++] = p->data;
        p = p->next;
    }
    p = first; // pointing p back to first node
    i--;

    // copying the elements back to linked list from array
    while (p != NULL) {
        p->data = A[i--];
        p = p->next;
    }
}

/* function to reverse the elements in linked list by reversing the links */
void reverse_links(struct node* p) {
    /* Here we are using the concept of sliding pointer that is why we have taken the two pointers
    p and q of node type as shown below */
    
    struct node* q = NULL;
    struct node* r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

/*recursive function to reverse te elements in the linked list */
void recursive_reverse(struct node* q, struct node* p) {
    if (p != NULL) {
        recursive_reverse(p, p->next);
        p->next = q;
    }
    else {
        first = q;
    }
}

/*function to concanate two linked lists */
void concat(struct node* p, struct node* q) {
    third = p;
    while (p->next != NULL)
        p = p->next;

    p->next = q;

}

/* function to merge two linked lists */
void merge(struct node* p, struct node* q) {
    struct node* last;
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p) last->next = p;
    if (q) last->next = q;

}

int isloop(struct node* f) {
    struct node* p, * q;
    p = q = f;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}
int main() {
    struct node* tail = NULL;
    int A[] = { 1,3,5,7,9,11 };
    int B[] = { 2,4,6,8,10,12 };
    create(A, 6); create2(B, 6);

    display(first);
    printf("\n");
    display(second);

    merge(first, second);
    printf("\n merged linked list:\n");
    display(third);




    /*recursive_reverse(tail,first);
    printf("\nAfter reversing the elements, the linked list is:\n");
    display(first);*/

    //printf("\n is sorted : %d\n", Is_sorted(first));
   /* Delete(first, 2);
    printf("\n");
    display(first);*/
    /*insert(first, 0, 10);
    printf("\n");
    display(first);*/
    
    
    /*
    temp = search1(first, 25);
    if (temp)
        printf("\nkey is found: %d\n", temp->data);
    else
        printf("\nKey is not found\n");

    display(first);*/
    return 0;

}