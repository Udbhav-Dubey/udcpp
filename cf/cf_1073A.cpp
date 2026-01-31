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
unordered_map<int,char>red;
unordered_map<int,char>blue;
for (int i=0;i<n;i++){
    cin>>arr[i];
    if (i%2==0){
        red[arr[i]]='R';
    }
    else {
        blue[arr[i]]='B';
    }
}
sort(all(arr));
bool flag=0;
for (int i=0;i<n-1;i++){
    if (red[arr[i]]==red[arr[i+1]]){flag=1;break;}
    if (blue[arr[i]]==blue[arr[i+1]]){flag=1;break;}
}
if (flag==1){
    cout << "NO\n";
}
else cout << "YES\n";
return ;
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

