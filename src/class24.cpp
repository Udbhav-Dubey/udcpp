#include <iostream>
using namespace std;
class box{
    private :
        int l,b,h;
        int *p;
    public :
        void setter(int l1,int b1,int h1,int x){
        l=l1;
        b=b1;
        h=h1;
        p=new int;
        *p=x;
            }
        void show(){
            cout << "\nleng = " << l;
            cout << "\n breadth = " << b;
            cout << "\n height = " << h;
            cout << "\n P int pointg to = " << p << endl;
        }       ~box(){
        delete p;
       
        }
};
int main (){
    box bo,bx;
    bo.setter(10,12,14,100);
    bo.show();
    box ox = bo;
    ox.show();
    bx = bo;
    bx.show();
    
return 0;
}
