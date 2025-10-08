#include<bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<n;i++){
            cin>>b[i];
        }
        bool flag=true;
        for (int i=0;i<n-1;i++){
            if (a[i]==b[i]) continue;
            if ((a[i]^a[i+1])==b[i]){
                a[i]^=a[i+1];
            }
            else {
                flag=false;
                break;
            }
        }
        if (a[n-1]!=b[n-1]) flag=false;
        cout << (flag?"YES":"NO") << "\n";
        }
return 0;
}
