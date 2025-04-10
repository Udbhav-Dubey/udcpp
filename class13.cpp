#include <iostream>
using namespace std;
class abc{
    public : 
    int x;
    abc(int y){
        x=y;
    }};
int main (){
    abc a(10);
    cout << a.x;
return 0;
}
