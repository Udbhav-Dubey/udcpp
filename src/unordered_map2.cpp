#include <iostream>
#include <unordered_map>
using namespace std;
int main  (){
    unordered_map<int,string>um;
    um.insert({1,"one"});
    um.insert({4,"four"});
    auto it = um.find(4);
    um.insert(it,{2,"two"});
    for (auto i:um){
        cout << i.first << "\t" << i.second << "\n";
    }
return 0;
}
