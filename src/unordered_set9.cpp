#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <int> vec={12,4324,2332,434662,954};
    unordered_set<int> s(vec.begin(),vec.end());
    for (auto x:s){
        cout << x << " ";
    }
return 0;
}
