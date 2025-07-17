#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n ;
    cin >> n;
    long long suming=((n)*(n+1))/2;
    long long x;
    long long muller=0;
    long long i = 2;
    while(cin>>x){
        muller+=x;
        if (i++==n){break;}
    }
    cout << suming - muller;
return 0;
}
