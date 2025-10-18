#include <iostream>
#include <set>
using namespace std;
int main (){
    set<int> s={1,5,3,23,423};
    int k=3;
    auto it=s.lower_bound(k);
    if (it!=s.end() && *it==k)
        cout << k << " is present. ";
    else cout << k << "is not present.";
return 0;
}
