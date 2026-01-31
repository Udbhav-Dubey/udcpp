#include <bits/stdc++.h>
using namespace std;

int main (){
    map<int,int>f;
    for (int p=2;p*p<=n;p++){
        while(n%p==0){
            f[p]++;
            n/=p;
        }
    }
    if (n>1)f[n]++;
    return 0;
}
