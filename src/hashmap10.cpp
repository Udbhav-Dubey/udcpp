#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,string> um={{1,"hustle"},{2,"loyalty"},{3,"respect"}};
    auto it=um.find(4);
    if (it!=um.end()){
        cout << it->first << ":" << it->second;
    }
    else    cout << "not found";
return 0;
}
