#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int>s={1,4,32,53,6};
    auto it = s.lower_bound(55);
    if (it!=s.end()) cout << *it;
    else cout << "lower bound not present.";
return 0;
}
