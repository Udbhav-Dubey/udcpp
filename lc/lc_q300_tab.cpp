#include <chrono>
#include <thread>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);    
                }
            }
        }
        int mx=0;
        for (int x:dp){
            mx=max(x,mx);
        }
        return mx;
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
