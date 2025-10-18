#include <iostream>
using namespace std;
class base {
    public : 
};
class A {
    public : 
        A(){
        cout << "A constructor" << endl;
        }   
};
class B : public A  {
    public :
};
class C : public A{
    public :
    C (){
        cout << "C constructor " << endl;
    }
};
class D {
    public : 
    D(){
        cout << "D constructor " << endl;
    }
    A a;
};
int main (){
    base Base;
    B b;
    C c;
    D d;
return 0;
}
