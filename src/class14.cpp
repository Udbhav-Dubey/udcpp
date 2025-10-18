#include <iostream>
using namespace std;
class A {
    public : 
        int val ;
        A(int x){
        val=x;
        }
        A(A&y){
        y.val=11;
            val = y.val;
        }
};
int main (){
    A a(20);
    cout << a.val <<endl;
    A a2(a);
    cout << a.val;
return 0;
}
