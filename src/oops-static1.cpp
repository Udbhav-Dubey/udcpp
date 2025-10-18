#include <iostream>
using namespace std;
class stMember{
    public :
        int val;
        stMember(int v=10):val(v){
            cout << "Static object created\n";
        }
};
class A{
    public :
        static stMember s;
        A(){cout << "A's constructor called "<< endl;}
};
stMember A::s=stMember(11);
int main (){
    cout << "accessing static data member without object "<< A::s.val << endl;
    cout << "now creating object 1 : " << endl;
    A obj1;
    cout << obj1.s.val << endl;
    cout << A::s.val<< endl;
return 0;
}
