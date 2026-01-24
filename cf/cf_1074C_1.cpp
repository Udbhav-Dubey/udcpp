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
int mexy(vector<ll>&vec){
    set<ll> sety(vec.begin(),vec.end());
    int u=0;
    while(sety.count(u)){
        u++;
    }
    return u;
}
void solve() {
    int n;
    cin>>n;
    vector <ll> arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll max_mex=0;
    set<ll>c;
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            ll x=j-arr[i];
            if (c.count(x)){continue;}
            c.insert(x);
            vector<ll>vec;
            for (int k=0;k<n;k++){
              ll val=arr[k]+x;  
            if (val>=0){
                vec.push_back(val);
            }
            }
            ll mex=mexy(vec);
            max_mex=max(mex,max_mex);
        }
    }
    cout << max_mex << "\n";
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

