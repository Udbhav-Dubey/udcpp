#include <iostream>
using namespace std;
class udboi{
public : 
    int val;
    void show(){
        cout << "value : " << val << endl;
    }
};
int main (){
    udboi ud;
    ud.val=10;
    ud.show();
return 0;
}
