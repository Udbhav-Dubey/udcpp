#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solver(vector<int>&nums,int target,int &n,vector<int>&memo){;
    if (target==0){return 1;}
    if (target<0){return 0;}
    if (memo[target]!=-1){return memo[target];}
    int ans=0;
    for (int i=0;i<n;i++){
        ans+=solver(nums,target-nums[i],n,memo);
    }
   return memo[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>memo(target+1,-1);
     return solver(nums,target,n,memo);
    }
};
int main (){
    vector<int>nums={1,2,3};
    int target=4;
    Solution sol;
    cout << sol.combinationSum4(nums,target);
    return 0;
}
