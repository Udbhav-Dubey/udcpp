#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>>memo;
    public:
    int solve(int i,int j,string &a,string &b){
        if (i==a.size())return b.size()-j;
        if (j==b.size())return a.size()-i;
        if (memo[i][j]!=-1)return memo[i][j];
        if (a[i]==b[j]){
            return memo[i][j]=solve(i+1,j+1,a,b);
        }
        int del=solve(i+1,j,a,b);
        int ins=solve(i,j+1,a,b);
        int rep=solve(i+1,j+1,a,b);
        return memo[i][j]=1+min({del,ins,rep});
    }
    int minDistance(string word1,string word2){
        memo.assign(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2);
    }
};
int main (){
    string word1 ="thala";
    string word2 ="forareason";
    Solution sol;
    cout << sol.minDistance(word1,word2);
    return 0;
}
