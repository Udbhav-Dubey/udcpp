#include <iostream>
using namespace std;
class enclosing {
    private :
        int x;
        class Nested {
            int y;
            void NestedFun(enclosing *e){
                cout <<e->x;
            }
        };
};
int main() {
return 0;
}
