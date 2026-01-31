#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(string &s,int i,vector<int>&memo,int &n){
        if (i==n){return 1;}
        if (s[i]=='0'){return 0;}
        if (memo[i]!=-1){return memo[i];}
        int ways=solve(s,i+1,memo,n);
        if (i+1<n&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))){
            ways+=solve(s,i+2,memo,n);
        }
    return memo[i]=ways;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>memo(n,-1);
        return solve(s,0,memo,n);
    }
};
int main (){
    Solution sol;
    vector<string>test={"12","226","06"};
     for (string &s:test){
        cout << s <<" : "<< sol.numDecodings(s) <<"\n";
    }
    return 0;
}
