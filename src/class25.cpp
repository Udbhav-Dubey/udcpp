#include <iostream>
using namespace std;
class box {
    private :
        int l,h;
        int* b;
    public : 
        box(){
            b=new int;
        }
        void setter(int l1,int b1,int h1){
            l=l1;
            *b=b1;
            h=h1;
        }
        void show(){
        cout << "length = " << l
             << "\n breadth = " << *b 
             << "\n height = "<< h
             << endl;
        }
        box(box & sample){
            l=sample.l;
            b=new int ;
            *b=*(sample.b);
            h=sample.h;
        }
        ~box(){
            delete b;
        }
};
int main (){
box first;
first.setter(12,14,16);
first.show();
box second = first;
second.show();
return 0;
}
