#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,int>mp;
    mp[5]=10;
    cout << mp[5] << endl;
    mp[69]=39;
    mp[5]+=5;
    if (mp.find(5)!=mp.end()){
        cout << "key 5 exists " << endl;
    }
    for (auto it : mp){
        cout << it.first << " -> " << it.second << endl;
    }

return 0;
}
