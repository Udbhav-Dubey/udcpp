#include <iostream>
using namespace std;
void fun(){
class test{
    public :
        void method();
};
void test::method(){cout << "local class method()";}
test t;
t.method();
}
int main (){
fun();
return 0;
}
