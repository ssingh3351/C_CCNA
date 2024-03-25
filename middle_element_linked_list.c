#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first = NULL;

void create_node(int A[], int n){
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i = 1; i < n; i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;        
    }
}
void display_node(struct node *p){
    while(p!= NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int middle_node(struct node *p){
    struct node *q;
    p=q=first;
    while(q){
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    return p->data;
}
int  main(){
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    create_node(A, 10);
    display_node(first);
    int middle_element  = middle_node(first);
    printf("\nmiddle element : %d\n",middle_element);
    return 0;
}