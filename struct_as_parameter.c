#include<Stdio.h>

struct Rectangle{
    int length;
    int breadth;
};

/*this is call by value method*/
// int area(struct Rectangle r1){
//     return r1.length*r1.breadth ;
// }

// int main(){
//     struct Rectangle r = {10,5};
//     printf("Area: %d\n",area(r));
// }

/*This is call by Address method*/
void changelength(struct Rectangle *p, int l){
    p->length = l;
}

int main(){
    struct Rectangle r = {10,5};
    changelength(&r, 20);
    printf("\n%d", r.length);
    return 0;
}