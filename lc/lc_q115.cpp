#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int ns=s.size(),nt=t.size();
        vector<unsigned long long>dp(nt+1,0);
        dp[0]=1;
        for (int i=1;i<=ns;i++){
            for (int j=nt;j>=1;j--){
                if (s[i-1]==t[j-1]){
                    dp[j]+=dp[j-1]; 
                }
            }
        }
        return dp[nt];
    }
};
int main (){
    vector<pair<string,string>>test={{"rabbbit","rabbit"},{"babgbag","bag"},{"aaaaa","aaa"}};
    Solution sol;
    for (auto p:test){
        cout << p.first << "  " << p.second <<"\n";
        cout << sol.numDistinct(p.first,p.second) << "\n";
    }
return 0;
}
