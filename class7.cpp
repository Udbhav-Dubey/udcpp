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
        friend void friendFunction(base &obj);
};
void friendFunction(base &obj){
    cout << "private " << obj.x << endl;
    cout << "public " << obj.y << endl;
}
int main (){
    base b;
    friendFunction(b);
return 0;
}
