#include <bits/stdc++.h>
using namespace std;
int main (){
    vector<int>v={1,2,3,4,5};
    v.erase(v.begin()+1,v.begin()+4);
    for (auto i:v){
        cout << i << " ";
    }
return 0;
}
