#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int> uset;
    cout << "uset.insert(1).second: " << uset.insert(1).second<<endl;
    cout << "*(uset.insert(1).first: "<<*(uset.insert(1).first)<<endl;
    cout << "uset.insert(1).second: " << uset.insert(1).second<<endl;
    cout << "*uset.insert(1).first: " <<*(uset.insert(1).first)<<endl;
    cout << "uset.insert(2).second: " <<uset.insert(2).second
return 0;
}
