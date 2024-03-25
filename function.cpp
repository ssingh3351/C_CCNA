#include <stdio.h>
// int add(int a, int b){
//     int c;
//     c=a+b;
//     return c;
// }
// int main(){
//     int x,y,z;
//     x=10;
//     y=5;
//     z=add(x,y);
//     printf("sum is %d",z);
//     return 0;
// }

void swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main(){
    int a,b;
    a=10;
    b=20;
    swap(a,b);
    printf("a=%d,b = %d", a,b);
    return 0;

}