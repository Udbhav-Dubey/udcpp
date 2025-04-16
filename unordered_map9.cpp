#include <iostream>
#include <unordered_map>
using namespace std;
void checkKey(unordered_map<int,string>&um,int key){
    if (um.find(key)==um.end()){
        cout << "not present\n"; 
    }
    else {cout << "present\n";}
}
int main (){
    unordered_map<int,string>um={{1,"one"},{2,"two"},{3,"three"}};
    checkKey(um,2);
    checkKey(um,4);
return 0;
}
