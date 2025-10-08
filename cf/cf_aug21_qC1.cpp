#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<long long> melons,cost;
    melons.push_back(1);
    cost.push_back(3);
    for (int x=1;x<=18;x++){
        long long m=1;
        for (int i=0;i<x;i++){m*=3;}
            melons.push_back(m);
            long long c=(x+2)*m+1;
            cost.push_back(c);
    }
    int t;
    cin>>t;
    while(t--){
        long long n;cin>>n;
        long long ans=0;
        for (int i=(int)melons.size()-1;i>=0;i--){
            while(n>=melons[i]){
                n-=melons[i];
                ans+=cost[i];
            }
        }
        cout << ans << "\n";
    }
return 0;
}
