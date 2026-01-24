#include <iostream>
using namespace std;
class A{
    private:
        int val;
    public:
        explicit A(int v):val{v}{};
        bool isequalto_member(const A &b){
            return val==b.val;
        }
        friend bool isequalto_nonMember(const A &a,const A &b);
};
bool isequalto_nonMember(const A&a,const A&b){
    return a.val==b.val;
}
int main (){
    A a(5);
    A b(5);
    cout << a.isequalto_member(b) << "\n";
    cout << isequalto_nonMember(a,b) << "\n";
return 0;
}
