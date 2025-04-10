#include <iostream>
using namespace std;
class test{
    private :
        int x;
        int y;
    public :
        test(int x=0,int y=0){this->x=x+2;this->y=y-2;}
        void fun2(){
            cout << x << y << endl;
        }
};
int main (){
    test obj;
    obj.fun2();
    return 0;
}
