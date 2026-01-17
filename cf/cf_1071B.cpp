#include <bits/stdc++.h>
using namespace std;
int main (){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    if (n<=1){cout << 0 << endl; continue;}
    vector<long long int>arr(n);
    long long sum=0;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n-1;i++){
        sum+=abs(arr[i]-arr[i+1]);
    }
    long long max_gain=abs(arr[0]-arr[1]);
    max_gain=max(max_gain,abs(arr[n-2]-arr[n-1]));
    for (int i=1;i<n-1;i++){
        long long dif=abs(arr[i]-arr[i-1])+abs(arr[i]-arr[i+1]);
        long long greed=abs(arr[i-1]-arr[i+1]);
        long long gain=dif-greed;
        max_gain=max(max_gain,gain);
    }
    cout << sum-max_gain << endl;
}
}
