#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total=accumulate(stones.begin(),stones.end(),0);
        int target=total/2;
        vector<bool>dp(target+1,false);
        dp[0]=1;
        for (int x:stones){
            for (int t=target;t>=x;t--){
                dp[t]=dp[t]||dp[t-x];
            }
        }
        for (int t=target;t>=0;t--){
            if (dp[t]){
                return total- 2 * t;
            }
        }
        return total;
    }
};
int main (){
    Solution sol;
    vector<int>stones1={2,7,4,1,8,1};
    vector<int>stones2={31,26,33,21,40};
    cout << sol.lastStoneWeightII(stones1) << "\n";
    cout << sol.lastStoneWeightII(stones2) << "\n";
    return 0;
}
