#include <bits/stdc++.h>
using namespace std;
int main (){
    int arr[]={11,23,45,89};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v={arr,arr+n};
    for (auto i:v){cout << i << " ";}
    return 0;
}
