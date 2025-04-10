#include <iostream>
using namespace std;
class A {
    private : 
        int var1;
    protected :
        int var2;
    public : 
        A (){
            var1=10;
            var2=69;
        }
        friend class F;
};
class F {
    public :    
        void displays(A& t){
            cout << "private " << t.var1 << endl; 
            cout << "protected one " << t.var2 << endl;
        }
};
int main (){   
    A a;
    F f;
    f.displays(a);
return 0;   
}
