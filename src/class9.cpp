#include <iostream>
using namespace std;
class base;
class another{
    public :
    void memberfunction(base & obj);
};
class base {
    private : 
        int x;
    protected : 
        int y;
    public :
            base (){
                cin >> x >> y;
                cout << "just did constructor\n";
            }
        friend void another::memberfunction(base&);
};
void another::memberfunction(base&obj){
    cout << "x" << obj.x << endl;
    cout << "y" << obj.y << endl;
}
int main (){
    base b;
    another object2;
    object2.memberfunction(b);
return 0;
}
