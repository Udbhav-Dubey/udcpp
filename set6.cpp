#include <bits/stdc++.h>
using namespace std;
int main (){
    int arr[]={11,423,232};
    int n=sizeof(arr)/sizeof(arr[0]);
    set<int>s(arr,arr+n);
    for (auto i : s){
        cout << i << " ";
    }
return 0;
}
