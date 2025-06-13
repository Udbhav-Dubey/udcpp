#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int>s1={1,2,4,5,23,23};
    unordered_set<int>s2(s1);
    for (auto it : s1){
        cout << it << " ";
    }
return 0;
}
