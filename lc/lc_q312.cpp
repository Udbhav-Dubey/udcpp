#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+2,1);
        for (int i=1;i<=n;i++){
            arr[i]=nums[i-1];
        }
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for (int len=1;len<=n;len++){
            for (int l=1;l<=n-len+1;l++){
                int r=len+l-1;
                for (int k=l;k<=r;k++){
                    dp[l][r]=max(dp[l][r],arr[l-1]*arr[k]*arr[r+1]+dp[l][k-1]+dp[k+1][r]);
                }
            }
        }
       return dp[1][n]; 
    }
};
int main (){
    vector<vector<int>>nums={{3,1,5,8},{1,5}};
    Solution sol;
    for (auto n:nums){
        cout << sol.maxCoins(n) << "\n";
    }
    return 0;
}
