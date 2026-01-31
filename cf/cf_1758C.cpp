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
    int n,x;
    cin>>n>>x;
    if (n%x){cout << -1 << "\n";return ;}
    vector<int>ans(n+1);
    iota(ans.begin(),ans.end(),0);
    ans[n]=1;
    ans[1]=x;
    while(x<n){
        for (int i=x*2;i<=n;i+=x){
            if (n%i==0){
                ans[x]=i;
                x=i;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i] <<" ";
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

