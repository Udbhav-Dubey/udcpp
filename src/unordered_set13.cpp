#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int> set={0,321,5,324,3,5324};
    for (auto i : set ){
        cout << i << " ";
    }
    cout << endl<< set.count(0);
    cout << endl<< set.count(1) << endl;
    set.erase(324);
    auto it1=set.begin();
    auto it2=next(it1,2);
    set.erase(it1,it2);
    for (auto i : set){
        cout << i << " ";
    }
return 0;
}
