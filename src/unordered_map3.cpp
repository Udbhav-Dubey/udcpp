#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um;
    um.insert({{1,"one"},{2,"two"},{3,"three"}});
    for (auto i:um){
        cout << i.first << "\t" << i.second << '\n';
    }
return 0;
}
