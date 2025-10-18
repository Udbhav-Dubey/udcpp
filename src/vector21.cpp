#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int>v={1,3,2};
    v.emplace(v.end(),6);
    for (auto i:v){cout << i << " ";}
return 0;
}
