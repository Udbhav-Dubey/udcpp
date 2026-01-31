#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int offset;
    int solve(vector<int>&nums,int target,int i,vector<vector<int>>&memo){
        if (target<-offset||target>offset){return 0;}
        if (i==n&&target!=0){return 0;}
        if (i==n&&target==0){return 1;}
        if (memo[i][target+offset]!=INT_MIN){return memo[i][target+offset];}
        return memo[i][target+offset]=solve(nums,target-nums[i],i+1,memo)+solve(nums,target+nums[i],i+1,memo);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        int maxy=accumulate(nums.begin(),nums.end(),0);
        offset=maxy;
        vector<vector<int>>memo(n,vector<int>(2*maxy+1,INT_MIN));
        return solve(nums,target,0,memo);
    }
};
int main (){
    vector<int>nums={1,1,1,1,1};
    int target=3;
    Solution sol;
    cout << sol.findTargetSumWays(nums,target);
    return 0;
}
