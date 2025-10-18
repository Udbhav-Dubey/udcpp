#include <iostream>
using namespace std;
class A{
    public : 
        static int x;
};
int A::x=2;
int main (){
    A a;
    cout << "static member hai "<< A::x << endl;
return 0;
}
