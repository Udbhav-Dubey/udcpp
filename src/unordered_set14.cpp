#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int>set={12,32,4232,545};
    auto itr1=set.begin();
    auto itr2=set.begin(2);
    auto itr3=set.end();
    auto itr4=set.end(2);
    cout << *itr2 << endl;
return 0;
}
