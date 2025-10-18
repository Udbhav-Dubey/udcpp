#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int>st={10,230,2323,232,211,2,45,6434};
    for (auto it : st){
        cout << it << " ";
    }
    cout << endl;
    auto first =next(st.begin(),1);
    auto last=next(st.begin(),5);
    st.erase(first,last);
    for (auto it : st) cout << it << " ";
return 0;
}
