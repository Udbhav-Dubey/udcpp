#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int> st={10,20,30,40};
    st.erase(20);
    st.erase(st.begin());
    for (auto i : st){
        cout << i << ' ';
    }
return 0;
}
