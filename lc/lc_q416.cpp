#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }      
        if (sum%2==1){return false;}
        int target=sum/2;
        vector<bool>dp(target+1,false);
        dp[0]=1;
        for (int x:nums){
            for (int s=target;s>=x;s--){
                dp[s]=dp[s]||dp[s-x];
                cout << "dp [s] " << dp [s] << ", dp[s-x] : " << dp[s-x] << "s : " << s << ", x : " << x << " s-x : " << s-x<<"\n";
            }
        }
        return dp[target];
    }
};
int main (){
    Solution sol;
    vector<int>nums={1,2,5};
    cout << sol.canPartition(nums);
}
