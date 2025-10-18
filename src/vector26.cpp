#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int>v={1,4,5,2,6,7};
    cout << v.capacity()<<endl;
    v.push_back(11);
    cout << v.capacity()<< endl;
    v.push_back(55);
    cout << v.capacity()<<endl;
return 0;
}
