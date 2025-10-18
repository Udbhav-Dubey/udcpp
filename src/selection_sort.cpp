// selection sort
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
    //sorting 
    for (int i=0;i<vec.size();i++){
        int minimum=i;
        for (int j=i+1;j<vec.size();j++){
            if (vec[j]<vec[minimum]){
                minimum=j;
            }
        }
        swap(vec[i],vec[minimum]);
    }
    cout << "\nafter sorting : ";
    for (auto it : vec){
        cout << it << " ";
    }
    return 0;
}
