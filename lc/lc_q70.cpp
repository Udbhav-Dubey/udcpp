#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n,vector<int>&memo){
        if (n==0){return 0;}
        if (n==1){return 1;}
        if (n==2){return 2;}
        if (memo[n]!=-1){return memo[n];}
        return memo[n]=solve(n-1,memo)+solve(n-2,memo);
    }
    int climbStairs(int n) {
        vector<int>memo(n+1,-1);
        return solve(n,memo);
    }
};
int main (){
    Solution sol;
    cout <<sol.climbStairs(4);
    return 0;
}
