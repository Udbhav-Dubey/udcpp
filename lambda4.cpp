#include <bits/stdc++.h>
using namespace std;
int main (){
    int a=5,b=10;
    cout << "a:" << a << "\nb:"<<b <<endl;
    auto lambda1=[=](){cout <<a+b << "\n";};
    auto lambda2=[&](){b+=a;cout<<b<<"\n";};
    lambda1();
    lambda2();
     cout << "a:" << a << "\nb:"<<b <<endl;

return 0;
}
