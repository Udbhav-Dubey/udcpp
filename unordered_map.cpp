#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"can you"},{2,"smell"},{3,"what the rock is cooking"}};
    for (auto i: um){
        cout << i.first << " : " << i.second <<endl;
    }
return 0;
}
