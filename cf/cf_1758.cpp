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
    if (x<n&&2*x>n){
        cout << -1 << "\n";
        return ;
    }
    vector<int>p(n+1);
    for (int i=1;i<=n;i++){p[i]=i;}
    p[1]=x;
    p[n]=1;
    vector<int>multi;
    for (int i=x;i<=n;i+=x){
        multi.push_back(i); 
    }
    for (int i=0;i+1<(int)multi.size();i++){
        p[multi[i]]=multi[i+1];
    }
    p[multi.back()]=1;
    for (int i=1;i<=n;i++){
        cout << p[i] << " ";
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


