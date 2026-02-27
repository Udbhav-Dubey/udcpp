#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if (dp[i]!=-1){return dp[i];}
        int mb=1;
        for (int j=0;j<i;j++){
            if (nums[i]>nums[j]){
                mb=max(mb,1+solve(nums,j,dp));
            }
        }
        return dp[i]=mb;
    }
    int lengthOfLIS(vector<int>& nums) {
    n=nums.size();
    vector<int>dp(n,-1);
    int ans=0;
    for (int i=0;i<n;i++){
        ans=max(ans,solve(nums,i,dp));
    }
    return ans;
    }
};
int main (){
    auto start=std::chrono::steady_clock::now();
    Solution sol;
    vector<vector<int>>nums={{10,9,2,5,3,7,101,18},{0,1,0,3,2,3},{7,7,7,7,7,7,7}};
    for (auto num:nums){
        cout << sol.lengthOfLIS(num) << "\n";
    }
    auto end=std::chrono::steady_clock::now();
    auto dur=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout << dur.count() << "\n";
return 0;
}
