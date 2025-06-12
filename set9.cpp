#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int> s={1,4,543,232,32};
    auto it_32 = s.find(32);
    auto it_3  =s.find(3);
    for (auto i : s){
        cout << i << " " ;
    }
    cout << endl;
    if (it_32!=s.end()) cout <<  *it_32 << endl;
    else cout << "not found";
    if (it_3!=s.end()) cout << *it_3 << endl;
    else cout << "not found";
return 0;
}
