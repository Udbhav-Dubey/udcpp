#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int> s={1,2,5,6};
    cout << *s.upper_bound(3);
    auto it = s.upper_bound(6);
    if (it!=s.end())
        cout << *it;
    else cout << "\nupper bound not exists.\n";
    return 0;
}
