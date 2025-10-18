#include <iostream>
using namespace std;
class A{
    private :
        int x;
    public :
        void set(int x){
        this ->x=x;
            }
        void print(){cout << "x = " << x << endl;}
};
int main (){
    A obj;
    int x=20;
    obj.set(x);
    obj.print();
    return 0;
}
