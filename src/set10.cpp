#include <bits/stdc++.h>
using namespace std;
int main (){
    set <int> s={1,2,4,5};
    s.erase(4);
    s.erase(s.begin());
    for (auto i :s) cout << i << " " ;
return 0;
}
