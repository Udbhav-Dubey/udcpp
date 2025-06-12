include <bits/stdc++.h>
using namespace std;
int main (){
    set <int>s={1,5,44,3};
    cout << *s.lower_bound(4) << endl  ;
    cout << *s.lower_bound(45) << endl; 
    return 0;
}
