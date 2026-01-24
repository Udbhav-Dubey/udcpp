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
    vector<ll>arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_mex=0;
    set<ll>c;
    for(int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            c.insert(j-arr[i]);
        }
    }
    for (ll x:c){
        set<ll>inthere;
        for (int i=0;i<n;i++){
            ll val=arr[i]+x;
            if (val>=0 && val<=n){
                inthere.insert(val);
            }
        }
        int mex=0;
        while(inthere.count(mex)){
            mex++;
        }
        max_mex=max(mex,max_mex);
        if (max_mex==n){break;}
    }
    cout << max_mex<<"\n";
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

