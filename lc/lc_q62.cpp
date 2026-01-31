#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int m,int n,int i,int j,vector<vector<int>>&memo,vector<vector<bool>>&visited){
        if (i>=m||j>=n){return 0;}
        if (i==m-1&&j==n-1){return 1;}
        if (memo[i][j]!=-1){return memo[i][j];}
        return memo[i][j]=solve(m,n,i+1,j,memo,visited)+solve(m,n,i,j+1,memo,visited);
    }
    int uniquePaths(int m, int n) {
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return solve(m,n,0,0,memo,visited);
    }
};
int main(){
    Solution sol;
    cout << sol.uniquePaths(3,7);
    return 0;
} 
