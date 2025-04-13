#include <iostream>
using namespace std;
class test {
    int a;
    public :
    test(){a=1;}
    void func(int a) {cout <<this->a;}
};
int main (){
test obj;
obj.func(3);
return 0;
}
