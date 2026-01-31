#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int solve(vector<vector<int>>&triangle,vector<vector<int>>&memo,int i,int j){
        if (i==n-1){
            return triangle[i][j];
        }
        if (memo[i][j]!=INT_MAX){
            return memo[i][j];
        }
        int b1=solve(triangle,memo,i+1,j);
        int b2=solve(triangle,memo,i+1,j+1);
        return memo[i][j]=min(b1,b2)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         n=triangle.size();
        vector<vector<int>>memo(n,vector<int>(n,INT_MAX));
        return solve(triangle,memo,0,0);
    }
};
int main (){
Solution sol;
vector<vector<int>>triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
cout << sol.minimumTotal(triangle);
return 0;
}
