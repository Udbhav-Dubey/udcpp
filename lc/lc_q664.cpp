#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int i=0;i<n;i++){dp[i][i]=1;}
        for (int len=2;len<=n;len++){
            for (int l=0;l<n-len;l++){
                int r=len+l-1;
                dp[l][r]=dp[l+1][r]+1;
                for(int k=l+1;k<=r;k++){
                    if (s[l]==s[k]){
                        dp[l][r]=min(dp[l][r],dp[l+1][k-1]+dp[k][r]);
                }
            }
        }
        }
        return dp[0][n-1];
    }
};
int main (){
return 0;
}
