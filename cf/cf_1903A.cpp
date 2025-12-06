#include <bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >>k;
        vector<int>a(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        if (k>=2){
            cout << "YES\n";
            //continue;
        }
        else {
            bool ok=true;
            for (int i=0;i<n-1;i++){
                if (a[i]>a[i+1]){
                    ok=false;
                    break;
                }
            }
            cout << (ok?"YES":"NO")<<"\n";
        }
    }
    return 0;
}
