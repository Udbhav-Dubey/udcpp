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
    int n,H,M;
    cin>>n>>H>>M;
    int bed=H*60+M;
    int mini=1440;
    for (int i=0;i<n;i++){
        int h,m;
        cin>>h>>m;
        int alarm=h*60+m;
        int diff=alarm-bed;
        if (diff<0){
            diff+=1440;
        }
        mini=min(mini,diff);
    }
    cout << mini/60 << " " << mini%60 << "\n";
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

