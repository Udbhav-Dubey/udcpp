#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <int>v1;
    vector <int>v2;
    int arr[]={2,4,1};
    v1.assign(arr,arr+2);
    v2.assign(v1.begin(),v1.end());
    for (auto i:v1){cout << i << " ";}
    cout << endl;
    for (auto i:v2){cout << i << " ";}
return 0;
}
