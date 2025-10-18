#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"one"},{2,"two"},{3,"three"}};
    um.erase((um.begin(),1));
    for (auto i:um){
        cout << i.first << " : "<<  i.second << "\n";
    }
return 0;
}
