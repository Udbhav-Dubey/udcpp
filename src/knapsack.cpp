#include <bits/stdc++.h>
using namespace std;
int solve(int w,vector<int>&val,vector<int>&wt,int n,vector<vector<int>>&dp){
    for (int i=0;i<=n;i++){
        for (int j=0;j<=w;j++){
            if (i==0||j==0){dp[i][j]=0;}
            else {
                int pick=0;
                if (wt[i-1]<=j){
                    pick=val[i-1]+dp[i-1][j-wt[i-1]];
                }
                int notpick=dp[i-1][j];
                dp[i][j]=max(notpick,pick);
            }
        }
    }
    return dp[n][w];
}
int knapsack(int W,vector<int>&val,vector<int>&wt){
    int n=val.size();
    vector<vector<int>>memo(n+1,vector<int>(W+1,-1));
    return solve(W,val,wt,n,memo);
}
int main (){
    vector<int>val={1,2,3};
    vector<int>wt={4,5,1};
    int W=4;
    cout << knapsack(W,val,wt)<< "\n";
    return 0;
}
