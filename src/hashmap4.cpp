#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,int>freq;
    int arr[6]={4,5,1,2,0,4};
    for(int i=0;i<6;i++){
        freq[arr[i]]++;
    }
    int found = -1;
   for (auto i : freq){
        if (i.second==1){
            found =i.first;
            break;
        }
        cout << found << endl;
    }
        return 0;
} 
