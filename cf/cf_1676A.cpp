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
    string dig;
    cin>>dig;
    int sum1=0;
    int sum2=0;
    for (int i=0;i<3;i++){
        sum1+=dig[i]-'0';
        sum2+=dig[i+3]-'0';
    }
    string f;
    (sum1==sum2)?f="yes":f="no";
    std::cout << f << "\n";
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

