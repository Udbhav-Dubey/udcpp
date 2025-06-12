#include <bits/stdc++.h>
using namespace std;
int main (){
    set<int> s={1,2,4,2};
    if (s.count(2)){
        cout << "exists\n";
    }
    else cout << "nope";
        cout << s.count(2);
return 0;
}
