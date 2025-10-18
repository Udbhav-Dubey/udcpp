#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int> us={1,2,4,53,53332};
    for (auto it=us.begin();it!=us.end();it++)
        cout << *it << " ";
    us.erase(53);
    us.erase(us.begin());
    cout << endl;
    for (auto it=us.begin();it!=us.end();it++){
        cout << *it << " ";
    }
return 0;
}
