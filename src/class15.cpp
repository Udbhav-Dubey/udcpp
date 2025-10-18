#include <iostream>
using namespace std;
class A {
    private :
        int pri;
    public : 
        int z;
        A () {
        pri=12;
        }
        A(A&a){
        z=a.pri+10;
        }
};
int main (){
    A a1;
    A a2(a1);
    cout << a2.z;
return 0;
}
