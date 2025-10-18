#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um ;
    um={{1,"hustle"},{2,"royality"},{3,"respect"}};
    auto it = um.find(2);
    if (it!=um.end()){
        cout << it->first << ":" << it->second;   
    }
    else cout << "not found";
    return 0;
}
