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
    string str=to_string(n);
    if (str.size()==1){cout << n <<"\n";return ;}
    if (str.size()==2){
        cout << str[1] << "\n";return ;
    }
    cout << *min_element(str.begin(),str.end())<<"\n";    
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

