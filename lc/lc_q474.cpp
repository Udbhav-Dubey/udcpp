#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int s1;
    vector<vector<vector<int>>>dp;
    int solve(int i,int m_l,int n_l,vector<pair<int,int>>&cnt){
        if (i==s1){return 0;}
        if (m_l==0&&n_l==0){return 0;}
        if (dp[i][m_l][n_l]!=-1){return dp[i][m_l][n_l];}
        int skip=solve(i+1,m_l,n_l,cnt);
        int take=0;
        if (m_l>=cnt[i].first&&n_l>=cnt[i].second){
            take=1+solve(i+1,m_l-cnt[i].first,n_l-cnt[i].second,cnt);
        }
        return dp[i][m_l][n_l]=max(skip,take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
         s1=strs.size();
         vector<pair<int,int>>count;
         for (auto& s:strs){
            int ones=0;
            for (char c : s){
                if (c=='1')ones++;
            }
            int zeros=s.size()-ones;

            count.push_back({zeros,ones});
         }
        dp.assign(s1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,count);
    }
};
int main (){
    vector<string>strs={"10","0001","111001","1","0"};
    int m=5;
    int n=3;
    Solution sol;
    cout << sol.findMaxForm(strs,m,n) << "\n";
    return 0;
}
