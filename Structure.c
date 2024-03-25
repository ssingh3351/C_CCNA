struct Rectangle{
    int length, width, height;
};

#include<stdio.h>
int main(){
    // struct Rectangle r;
    struct Rectangle r = {10,5,4};
    printf("length:%d\n", r.length);
    printf("width: %d\n", r.width);
    printf("height: %d\n", r.height);
    printf("%d", sizeof(r));
    return 0;
}