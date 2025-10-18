#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"one"},{2,"two"},{3,"three"}};
    for (auto it=um.begin();it!=um.end();it++){
        cout << it->first << ":" << it->second << endl;
    }
return 0;
}
