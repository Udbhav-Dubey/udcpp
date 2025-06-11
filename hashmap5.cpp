#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,string> um={{1,"the y2j"},{2,"problem"},{3,"is here"}};
    for (auto i:um){
        cout << i.first << ":" << i.second << endl;
    }
    return 0;
}
