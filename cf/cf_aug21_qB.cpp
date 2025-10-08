#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long > xs;
        long long p=10;
        for (int k=1;k<=18;k++,p*=10){
            if (p>n) break;
            long long d=1+p;
            if (n%d==0){
                xs.push_back(n/d);
            }
        }
        if (xs.empty()){
            cout << 0 << "\n";
        }
        else {
            sort(xs.begin(),xs.end());
            cout << xs.size() << "\n";
            for (auto v:xs) cout << v << " ";
            cout << "\n";
         }
    }
        return 0;
}

