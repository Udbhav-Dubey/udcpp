#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int main (){
    unordered_set<string> set={"second","city"};
    string mystring="saint";
    set.insert(mystring);
    cout << "my set contains: "
        << endl;
    for (auto x: set){
    cout << x << " ";
    }
    cout << "\nupdated set\n";
    vector <string> vec={"the","best","in","the","world"};
    set.insert(vec.begin(),vec.end());
    for (auto x: set){
    cout << x << " ";
    }
    return 0;
}
