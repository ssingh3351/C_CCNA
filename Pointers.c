#include<stdio.h>
// int main(){
//     int a  = 10; // data variable
//     int *p;        //pointer variable
//     p = &a;
//     printf("a = %d\n", a);
//     printf("accessed using pointer, value of a = %d\n", *p);
// }

// int main(){
//     int *p;
//     p = (int*)malloc(sizeof(int));
//     // the malloc function returns a void pointer,
//     //Therefore, we are typacting it to int pointer.
// }

struct Rectangle{
    int length, width, height;
};

int main(){
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    printf("%d\n",sizeof(p1));
    printf("%d\n",sizeof(p2));
    printf("%d\n",sizeof(p3));
    printf("%d\n",sizeof(p4));
    printf("%d\n",sizeof(p5));

    return 0;

}