#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int> st={21,42,11};
    auto it =st.end();
    st.insert(it,1);
    for (auto i : st){
        cout << i << " ";
    }
return 0;
}
