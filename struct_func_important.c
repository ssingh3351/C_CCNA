#include<stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b){
    r->length = l;
    r->breadth = b;
}
int area(struct Rectangle r1){
    return r1.length*r1.breadth;
}
void changelength(struct Rectangle *r, int l){
    r->length = l;
}

int main(){
    struct Rectangle r;

    initialize(&r, 10,5);
    printf("%d\n",area(r));
    changelength(&r,20);
    printf("%d\n",area(r));
}