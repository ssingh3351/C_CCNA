#include<iostream.h>
#include<stdio.h>

using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
        Rectangle(){
            length =0;
            breadth =0;
        }
        Rectangle(int l, int b ){}
        int area(){
            return length*breadth;
        }
        int perimeter(){
            return 2*(length+breadth);
        }
        int getlength(){
            return length;
        }
        void getbreadth(){
            return breadth;
        }
        void setlength(int l){
            length=l;
        }
        void setbreadth(int b){
            breadth=b;
        }
        
        ~Rectangle();
};

int main(){
    Rectangle r(10,5);
    cout<<r.area();
    cout<<r.perimeter();
    r.setlength(20);
    cout<<r.getlength();
}