#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF=1e9;
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INF));
        dp[0][0]=grid[0][0];
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i==0&&j==0){continue;}
                int top=(i>0)?dp[i-1][j]:INF;
                int left=(j>0)?dp[i][j-1]:INF;
                dp[i][j]=min(top,left)+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
int main (){
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    cout << sol.minPathSum(grid) << "\n";
    return 0;
}
