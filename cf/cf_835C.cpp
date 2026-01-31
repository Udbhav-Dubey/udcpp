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
    int max1{};
    int max2{};
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i=0;i<n;i++){
        cin>>arr[i];
        if (arr[i]>=max1){
            max2=max1;
            max1=arr[i];
        }
        else if(arr[i]>=max2&&arr[i]!=max1){
            max2=arr[i];
        }
    }
    vector<int>ans(n);
    for (int i=0;i<n;i++){
        if (arr[i]==max1){
            ans[i]=arr[i]-max2;
        }
        else ans[i]=arr[i]-max1;
    }
    for (auto w:ans){
        cout << w << " ";
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

