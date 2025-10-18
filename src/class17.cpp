#include <iostream>
using namespace std;
class A {
    public : 
        int sum=0;
        A (int a, int b){
        sum = a+b;
        }
        void print(){cout << sum << endl;}
};
int main (){
    A obj1(10,20);
    A obj2(100,-400);
    obj1.print();
    obj2.print();
return 0;
}
