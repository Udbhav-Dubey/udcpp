#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string> um;
    um[1]="Geeks";
    um.insert({2,"for"});
    um.insert({3,"c++"});
    for (auto i:um){
        cout << i.first << ":" << i.second << endl;
    }
return 0;
}

