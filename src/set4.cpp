#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <int> vec={12,32,14,23,334};
    auto first =vec.begin();
    auto last = vec.end();
    set <int> st(last,first);
    for (auto i : st ){
        cout << i << " ";
    }
return 0;   
}
