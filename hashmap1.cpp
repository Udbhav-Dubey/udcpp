#include <bits/stdc++.h>
using namespace std;
int main (){
    int arr[]={1,2,1,3,2,1};
    unordered_map<int,int> freq;
    for (int i=0;i<6;i++){
        freq[arr[i]]++;
    }
    for (auto it : freq){
        cout << it.first << " appears " << it.second << " times " << endl;
    }

return 0;
}
