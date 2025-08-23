#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin >> n;
    vector <long long> nums(n);
    for (int i=0;i<n;i++){
        cin >> nums[i];
    }
    long long maxi=nums[0];
    long long current_sum=nums[0];
    for (int i=1;i<n;i++){
        current_sum=max(nums[i],nums[i]+current_sum);
        maxi=max(maxi,current_sum);
    }
    cout << maxi;
return 0;
}
