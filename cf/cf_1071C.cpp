#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long>arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    long long m=arr[0];
    long long k=m;
    for (int i=1;i<n;i++){
        k=gcd(k,arr[i+1]-arr[i]);
    }
    cout << k << "\n";
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}
