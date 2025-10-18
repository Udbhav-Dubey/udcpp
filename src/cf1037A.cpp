#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int dig=0;
        if (x<10){dig=x;}
        else while(x>0){
            int digi=x%10;
            dig=min(digi,dig);
        }
        cout << dig;
    }
return 0;
}

