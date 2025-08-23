#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    vector<long> vec(n);
    for(int i=0;i<n;i++){
       cin>> vec[i];
    }
    long ctr=0;
    for (int i=1;i<n;i++){
        if (vec[i]<vec[i-1]){
             ctr+=vec[i-1]-vec[i];
             vec[i]+=vec[i-1]-vec[i];
        }
    }
//    for (auto it : vec){
  //      cout << it << " ";
    //}
    cout<<endl << ctr << endl;
return 0;
}
