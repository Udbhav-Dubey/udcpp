#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int INF=1e9;
    int solve(vector<vector<int>>&grid,vector<vector<int>>&memo,int i,int j,int m,int n){
        if (i>=m||j>=n){return INF;}
        if (i==m-1&&j==n-1){return grid[i][j];}
        if (memo[i][j]!=-1){return memo[i][j];}
        return memo[i][j]=min(solve(grid,memo,i+1,j,m,n),solve(grid,memo,i,j+1,m,n))+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return solve(grid,memo,0,0,m,n);
    }
};
int main (){
    vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    cout << sol.minPathSum(grid) << "\n";
    return 0;
}
