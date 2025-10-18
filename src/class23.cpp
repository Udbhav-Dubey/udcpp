#include <iostream>
using namespace std;
class storeVal{
    public :
        storeVal(){}
        storeVal(const storeVal & s){
            cout << "copy constructor" << endl;
        }
    
};
storeVal(){
    storeVal obj;
    return obj;
}
void foo2(storeVal&obj){return ;}
int main (){
    storeVal obj1;
    cout << "case 1 : ";
    foo();
    cout << endl;
    cout << "case 2 : ";
    foo2(obj);
    cout << endl;
    cout << "case 3: ";
    storeVal obj2=obj1;
    return 0;
}
