#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    set <long long > map;
    for (int i=0;i<n;i++){
        long long x;
        cin >> x;
        map.insert(x);
    }
    cout << map.size();
return 0;
}
