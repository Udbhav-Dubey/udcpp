#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<int,string>um={{1,"L"},{2,"A"},{3,"Knight Yeah"}};
    um.erase(2);
    for (auto i:um){
        cout << i.first << ":" << i.second << endl;
    }
return 0;
}
