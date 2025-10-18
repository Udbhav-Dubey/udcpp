#include <iostream>
using namespace std;
class A {
    private: 
        int x=10;
    public :
        int b;
        A(){
        setter();
        }
        void setter(){
            b=x;
        }
    
};
int main (){
    A a;
    cout << a.b;
return 0;
}
