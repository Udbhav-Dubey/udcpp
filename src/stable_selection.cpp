#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <int> vec;
    int x;
    while(cin>>x){
        vec.push_back(x);
        if (cin.peek()=='\n') break;
    }
    cout << "before sorting : ";
    for (auto it : vec){
        cout << it << " ";
    }
    // sorting 
    for (int i=0;i<vec.size-1;i++){
        int mini=i;
        for (int j=i+1;j<n;j++){
            if (vec[min]>vec[j]){
                min=j;
            }
            int key=a[min];
            for (int k=min;k>i;k--){
                a[k]=a[k-1];}
              
            a[i]=key;
        }
    } 
    return 0;
}
