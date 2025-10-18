#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int>v={1,3,56,32};
    v.pop_back();
    v.pop_back();
    v.shrink_to_fit();
    cout << v.capacity()<<endl;
return 0;
}
