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
    vector<int>vec(n+1);
    bool flag=1;
    for (int i=1;i<=n;i++){
        cin>>vec[i];
    }
    for (int i=1;i<=n;i++){
        int v=vec[i];
        int target=i;
        while(v>0&&v%2==0)v/=2;
        while(target>0&&target%2==0)target/=2;
        if (v!=target){
            flag=0;
            break;
        }
    }
    if (flag){cout << "YES\n";}
    else cout << "No\n";
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

