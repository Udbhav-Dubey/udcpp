#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int>v={1,4,3};
    v.emplace(v.begin()+2,6);
    for (auto i : v)
        cout << i << " ";
return 0;
}

