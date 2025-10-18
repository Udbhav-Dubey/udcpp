#include <bits/stdc++.h>
using namespace std;
int main (){
    set<int>s={1,23,5,323,4};
    auto it1 = s.begin();
    auto it2= next(it1,2);
    for (auto it : s){
        cout << it << " ";
    }
    cout << endl << *it1 << endl;
    cout << *it2 << endl;
    cout << *next(s.begin(),4);
return 0;
}
