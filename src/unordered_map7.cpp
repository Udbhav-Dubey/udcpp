#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"geeks"},{2,"for"},{3,"geeks"}};
    um[2]="need";
    for (auto i:um){
        cout << i.first << '\t' << i.second << endl;
    }
return 0;
}
