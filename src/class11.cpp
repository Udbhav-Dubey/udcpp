#include <iostream>
using namespace std;
class A;
class B{
    private : 
        int x;
    public :
        void set(int a){
            x=a;
        }
    friend void max(A&,B&);
};
class A {
    private :
        int y;
    public : 
        void set(int b){
        y=b;
        }
        friend void max(A&,B&);
};
void max (A &t1,B &t2){
    (t1.y>t2.x)? cout << t1.y : cout << t2.x ;
}
int main (){
    A aa;
    B bb;
    aa.set(100);
    bb.set(200);
    max(aa,bb);
return 0;
}
