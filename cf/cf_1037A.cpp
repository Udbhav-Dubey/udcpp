#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int x_copy=x;
        int minimum=11;
        while(x>0){
            int dig=x%10;
            x=x/10;
            if (dig<minimum){
                minimum=dig;
            }
        }
        cout << minimum << endl;
    }
    return 0;
}
