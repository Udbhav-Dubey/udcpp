#include <iostream>
using namespace std;
class rectangle {
    private : 
        int l,b;
    public : 
        int getValues(){
            return l,b;
        }
        void setValues(int le,int br){
            l=le;
            b=br;
        }
        int area(){
                return l*b;}
};
int main (){
    rectangle obj;
        obj.setValues(10,20);
    
    cout << obj.getValues() << "X" << obj.area();
return 0;
}
