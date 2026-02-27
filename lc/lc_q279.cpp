#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int inf=1e9;
    int numSquares(int n) {
        vector<int>dp(n+1,inf);
        dp[0]=0;
        vector<int>s;
        for (int i=1;i*i<=n;i++){
            s.push_back(i*i);
        }
        for (int i=1;i<=n;i++){
            for (int c:s){
                if (c>i){break;}
                    dp[i]=min({dp[i],dp[i-c]+1});
        }
        }
        return dp[n];
    }
};
int main (){
    vector<int>arr={12,13};
    Solution sol;
    for (int i=0;i<arr.size();i++){
        cout << arr[i] << "  " << sol.numSquares(arr[i]) << "\n";
    }
return 0;
}
