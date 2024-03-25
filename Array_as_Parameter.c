#include<stdio.h>

int fun(int *a, int n){
    int i;
    for (i=0; i<n; i++)
        printf("%d ",  a[i]);
}

int main(){
    int a[5] = {2,4,6,8,10};
    fun(a,5);
    return 0;
}