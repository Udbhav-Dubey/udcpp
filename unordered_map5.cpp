#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,string>um={{1,"one"},{2,"two"},{3,"three"}};
    cout << um[2] << endl;
    cout <<um.at(2);
return 0;
}
