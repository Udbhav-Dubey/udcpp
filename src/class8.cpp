#include <iostream>
using namespace std;
class base {
    private : 
        int x;
    protected : 
        int y;
    public : 
        base(){
            cin >> x >> y;
            cout << "i just took x and y in a constructor\n";
        }
        friend int friendFunction(base &obj,int t);
};
int friendFunction(base &obj,int t){
    cout << "private " << obj.x *t  << endl;
    cout << "public " << obj.y * t<< endl;
    return 0;
}

int main (){
    base b;
    friendFunction(b,10);
return 0;
}
