#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"finish"},{2,"the"},{3,"story"}};
    for (auto it=um.begin();it!=um.end();it++){
        cout << it->first << ":" << it->second << endl;
    }
return 0;
}
