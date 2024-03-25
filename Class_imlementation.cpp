#include<iostream>

class Rectangle{
    int length;
    int breadth;

    void initialize(int l, int b){
        length = l;
        breadth = b;
    }
    int area(){
        return length*breadth;
    }
    void changelength(int l){
        length = l;
    }

int main(){
    Rectangle r;

    r.initialize(10,5);
    printf("%d\n",r.area());
    r.changelength(20);
    printf("%d\n",r.area());
}