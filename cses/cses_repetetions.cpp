#include <bits/stdc++.h>
using namespace std;
int main (){
    string s;
    cin>>s;
    int n=s.size();
    int max_len=1,current=1;
    for (int i=0;i<n;i++){
        if (s[i]==s[i+1]){
            current++;
        }
        else {
            current=1;
        }
        max_len=max(max_len,current);
    }
    cout << max_len << "\n";
return 0;
}
