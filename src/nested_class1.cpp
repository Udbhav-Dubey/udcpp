#include <iostream>
using namespace std;
class enclosing {
    int x;
    class nested {
        int y;
    };
    void enclosingFun(nested *n){
            cout <<n->y;
    }
};
int main (){
return 0;
}
