#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    while(b){
        long long temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long >a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        long long answer=-1;
        for (long long x=2;x<=100;x++){
            bool found=false;
            for (int i=0;i<n;i++){
                if (gcd(a[i],x)==1){
                    found=true;
                    break;
                }
            }
            if (found){
            answer=x;
            break;
            }
        }
        cout << answer<<"\n";
    }
    return 0;
}
