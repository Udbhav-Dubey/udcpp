#include <iostream>
using namespace std;
class B;
class A{
private:
    int val;
public:
    explicit A(int x):val{x}{};
    friend bool compare(const A&a,const B&b);
};
class B{
    int val;
public:
    explicit B(int x):val{x}{};
    friend bool compare(const A&a,const B&b);
};
bool compare(const A&a,const B&b){
    return a.val==b.val;
}
int main (){
    A a(5);
    B b(1);
    cout << compare(a,b);
    return 0;
}
