#include <iostream>
using namespace std;
int x;
void fun(){
class test1{
    public :
        test1(){
            cout << "test1 :: test1()" << endl;
        }
};
class test2{
    test1 t1;
    public :
    void method(){
        cout << "x = " << x << endl;
    }
};
test2 t;
t.method();
}
int main (){
fun();
return 0;
}
