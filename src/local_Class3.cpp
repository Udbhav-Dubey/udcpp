#include <iostream>
using namespace std;
void fun(){
static int x=3;
enum{i=1,j=2};
class test{
    public :
        void method(){
            cout << "x== " << x << endl;
            cout << "i==" << i << endl;
        }
};
test t;
t.method();
}
int main(){
    fun();
return 0;
}
