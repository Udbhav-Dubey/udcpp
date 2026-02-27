#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size()<word2.size()){swap(word1,word2);}
        int n=word1.size();
        int m=word2.size();
        vector<int>dp(m+1,0);
        for (int i=1;i<=n;i++){
            int prev=0;
            for (int j=1;j<=m;j++){
                int temp=dp[j];
                if (word1[i-1]==word2[j-1]){
                    dp[j]+=1;
                }
                else {
                    dp[j]=max{dp[j],dp[j-1];}
                }
                prev=temp;
            }
        }
        int maxy=dp[m];
        int x=m-maxy;
        int y=n-maxy;
        return x+y;
    }
};
