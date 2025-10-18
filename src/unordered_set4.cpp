#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int> uset ={15,32,232};
    auto it = uset.find(15);
    if (it!=uset.end())cout << *it;
    else cout << "element not found";
return 0;
}
