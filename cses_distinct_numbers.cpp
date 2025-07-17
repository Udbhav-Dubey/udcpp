#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    vector <long long int> nums(n);
    for (int i=0;i<n;i++){
        cin >> nums[i];
    }
    unordered_map<long long int,long long int> maps;
    int ctr=0;
     maps[0]=0;
    for (int i=0;i<n;i++){
        if (maps.find(nums[i])==maps.end()){
            ctr++;
        }
        maps[nums[i]]=i;
    }
    cout << ctr;
return 0;
}
