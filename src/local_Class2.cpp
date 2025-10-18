#include <iostream>
using namespace std;
void fun(){
class test {
    public :
    static void method(){
    cout << "local class method()called";
}
};
test::method();
}
int main (){  
    fun();
return 0;
}
