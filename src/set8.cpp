#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int>s1={1,423,53,2};
    int i=2;
    auto it =s1.begin();
    advance(it,i);
    for (auto i : s1){
        cout << i << " ";
    }
    cout << endl <<*it << endl;
    cout << *next(s1.begin(),2) << endl;
    return 0;
}
