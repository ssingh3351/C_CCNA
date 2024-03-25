// void func1(int n){
//     if(n>0){
//         func1(n-1);
//         printf("%d\n",n);
//     }
// }

void fun(int n){
    while(n>0){

    }
}
void main(){
    int x = 3;
    func1(x);
}



void fun(int n)
{
 if(n>0)
 {
 printf("%d", n);

 fun(n-1);
 fun(n-1);
 }
}
fun(3);