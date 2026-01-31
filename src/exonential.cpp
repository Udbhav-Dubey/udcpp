#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a;
    long long e;
    long long m;
    long long res=1%m;
    a%=m;
    while(e){
        if (e&1){
            res=(res*a)%m;
        }
        a=(a*a)%m;
        e>>1;
    }
    return 0;
}
