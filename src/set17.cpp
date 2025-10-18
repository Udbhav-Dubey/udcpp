#include <bits/stdc++.h>
using namespace std;
int main (){
    set<string>s={"hello","geeks","welcome"};
    for (auto it : s){
        cout << it << " " << endl;
    }
    cout << endl<< *s.lower_bound("coding");
return 0;
}
