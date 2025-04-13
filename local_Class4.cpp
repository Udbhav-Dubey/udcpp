#include <iostream>
using namespace std;
void fun(){
int x;
class test {
    public :
        void method(){
            cout << "x= " << x << endl;
        }
};
test t;
t.method();
}
int main (){
return 0;
}
