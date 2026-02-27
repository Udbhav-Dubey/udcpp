#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if (n==1){return 0;}
        vector<vector<bool>>pal(n,vector<bool>(n,0));
        for (int i=n-1;i>=0;i--){
            for (int j=i;j<n;j++){
                if (s[i]==s[j]&&(j-i<=2||pal[i+1][j-1]==1)){
                    pal[i][j]=true;
                }
            }
        }
        vector<int>dp(n,0);
        for (int i=0;i<n;i++){
        if (pal[0][i]==1){dp[i]=0;}
        else {
            dp[i]=i;
            for (int j=0;j<i;j++){
                if (pal[j+1][i]){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
        }
        }
        return dp[n-1];
    }
};
int main (){
vector<string>str={{"aab"},{"a"},{"ab"}};
Solution sol;
for (auto s:str){
    cout << sol.minCut(s) << "\n";
}
return 0;
}

