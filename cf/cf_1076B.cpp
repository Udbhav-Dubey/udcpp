#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
const ll inf = 1e18;
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin>>n;
    vector<int>arr(n);
    unordered_map<int,int>mp;
    for (int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]=i;
    }
    int l{-1};
    for (int i=0;i<n;i++){
        if (arr[i]!=n-i){l=i;break;}
    }
    if (l==-1){
        for (int i=0;i<n;i++){cout << arr[i] << (i==n-1 ? "" : " ");}
        cout <<"\n";
        return ;
    }
    int r=mp[n-l];
    for (int j=0;j<l;j++){
        cout << arr[j] << " ";
    }
    for (int j=r;j>=l;j--){
        cout << arr[j] << " "; 
    }
    for (int j=r+1;j<n;j++){
        cout << arr[j] << " ";
    }
    cout << "\n";
}
int main() {
    fastio;

    int t = 1;
    cin >> t;        // comment this if no multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}
