#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>&obstacleGrid,vector<vector<int>>&memo,int i ,int j,int n,int m){
        if (i>=m||j>=n){
            return 0;
        }
        if (obstacleGrid[i][j]==1){return 0;}
        if (memo[i][j]!=-1){return memo[i][j];}
        if (i==m-1&&j==n-1){return 1;}
        return memo[i][j]=solve(obstacleGrid,memo,i+1,j,n,m)+solve(obstacleGrid,memo,i,j+1,n,m);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1]==1){return 0;}
       //if (m==1 && obstacleGrid[0][0]==0){return 1;}
         if (m==1&&obstacleGrid[0][0]==1){return 0;}
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return solve(obstacleGrid,memo,0,0,n,m);
    }
};
int main (){
    vector<vector<int>>obstacle={{0,1,0,0}};
    Solution sol;
    cout << sol.uniquePathsWithObstacles(obstacle);
    return 0;
}
