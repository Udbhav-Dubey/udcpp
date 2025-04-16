#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"one"},{2,"two"},{3,"three"}};
    um.erase(2);
    um.erase(um.begin());
    for (auto it=um.begin();it!=um.end();it++){
        cout <<  it->first << ":" << it->second << endl;
    }
return 0;
}
