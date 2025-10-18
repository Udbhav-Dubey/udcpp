#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int> v{1,2,4};
    list<int>l{3,5};
    v.insert(v.begin()+3,l.begin(),l.end());
    for (auto i:v){
        cout << i << " ";
    }
return 0;
}
