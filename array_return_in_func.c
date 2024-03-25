#include<stdio.h>
#include<stdlib.h>
int * func(int n){
    int *p;
    p = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        p[i] =i+1;
    }
    return p;
}

int main(){
    int *A;
    A = func(5);
    for( int i =0; i < 5; i++){
        printf("%d\n",A[i]);
    }
    return 0;
}