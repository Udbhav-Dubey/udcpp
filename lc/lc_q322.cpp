#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF=1e9;
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0){
            return 0;
        }
        vector<int>dp(amount+1,INF);
        dp[0]=0;
        for (int a=1;a<=amount;a++){
            for (int c:coins){
                if (a-c>=0){
                dp[a]=min(dp[a],dp[a-c]+1);        
            }}
        }
        return dp[amount]==INF?-1:dp[amount];
    }
};
int main (){
    Solution sol;
    vector<vector<int>>coin{{1,2,5},{2},{1}};
    vector<int>am={11,3,0};
    for (int i=0;i<3;i++){
        cout << sol.coinChange(coin[i],am[i])<<"\n";
    }
    return 0;
}
