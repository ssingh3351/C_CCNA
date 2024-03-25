#include <stdio.h>

int main(){
    
    // int a[5] = {0,1,2,3,4};
    // printf("%d", sizeof(a));
    // for(int i = 0; i < 5; i++){
    //     printf("\n%d", a[i]);
    // }
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int a[n];
    a[0] = 2;
    for (int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
    printf("%d\n", sizeof(a));
    return 0;
}