#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,string> um;
    vector <pair<int,string>> v={{1,"one"},{2,"two"},{3,"three"}};
    um.insert(v.begin(),v.end());
    for (auto i:um){
        cout << i.first << ": " << i.second << endl;
    }
return 0;
}
