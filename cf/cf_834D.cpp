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
    ll n,m;
    cin>>n>>m;
    int cnt2=0;
    int cnt5=0;
    ll n1=n;
    ll k=1;
    while(n>0&&n%2==0){
        cnt2++;
        n/=2;
    }
    while(n>0&&n%5==0){
        cnt5++;
        n/=5;
    }
    while(cnt2<cnt5&&k*2<=m){
        cnt2++;
        k*=2;
    }
    while(cnt5<cnt2&&k*5<=m){
        cnt5++;
        k*=5;
    }
    while(k*10<=m){
        k*=10;
    }
    if (k==1){
        cout << n1*m<<"\n";
    }
    else {
        k*=m/k;
        cout << n1*k <<"\n";
    }
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

