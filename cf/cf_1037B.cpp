#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >>n;
        int k;
        cin >>k;
        int a[n];
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        int count=0;
        int answer=0;
        for (int i=0;i<n;i++){
            if (a[i]==1){
                count=0;
                continue;
            }
            else count++;
            if (count==k){
                answer++;
                count=0;
                i++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
