#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int>us={1,3,4,5,7};
    for (auto i : us){
        cout << i << " ";
    }
    auto it = next(us.begin(),2);
    advance(it,2);
    cout <<endl << *it << endl; 
return 0;
}
