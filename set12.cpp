#include <bits/stdc++.h>
using namespace std;
set <int> s1;
int main (){
    s1={1,2,4,2};
    cout << s1.size() << endl;
    set <int> s2;
    cout << s2.size() << endl;
    for (auto it : s1 ){
        cout << it << " " ;
    }
    cout << endl;
    int sum=0;
    while (s1.empty()==0){
        sum+=*s1.begin();
        s1.erase(s1.begin());
    }
    cout << sum;
    return 0;
}
