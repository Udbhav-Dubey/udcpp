#include <bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long  n,x;
        cin>>n>>x;
        vector<long long >a(n);
            a.push_back(0);
        for (long long i=0;i<n;i++){
            long long  point;
            cin>>point;
            a.push_back(point);
        }
        a.push_back(x);
        n=a.size();
        long long mdurf =INT_MIN;// max distance before refulling 
        for (int i=1;i<n;i++){
            if (i==n-1){
                mdurf=max(mdurf,2*(a[i]-a[i-1]));
            }
            else mdurf=max(mdurf,a[i]-a[i-1]);
        }
        cout << mdurf << endl;
    }
    return 0;
}
