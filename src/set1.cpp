#include <bits/stdc++.h>
using namespace std;
int main (){
    set<int>st;
    st.insert(3);
    st.insert(6);
    st.insert(1);
    st.insert(5);
    st.insert(3);
    for (auto i:st){
        cout << i << " " ;
    }
return 0;
}
