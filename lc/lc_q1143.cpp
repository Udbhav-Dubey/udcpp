#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.size();
        int s2=text2.size();
        vector<vector<int>>dp(s1+1,vector<int>(s2+1,0));
        for (int i=1;i<=s1;i++){
            for (int j=1;j<=s2;j++){
                if (text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
                    }
            }
        }
        for (int i=0;i<=s1;i++){
            for (int j=0;j<=s2;j++){
                cout << dp[i][j] << "  ";
            }
            cout << "\n";
        }
        return dp[s1][s2];        
    }
};
int main (){
    string t1="abcde";
    string t2="ace";
    Solution sol;
    cout << sol.longestCommonSubsequence(t1,t2)<<"\n";
    return 0;
}
