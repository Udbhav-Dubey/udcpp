#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n,vector<int>&cache){
        if (n<=0){return 0;}
        else if (n==1||n==2){return 1;}
        if (cache[n]!=-1){return cache[n];}
        int ans=solve(n-1,cache)+solve(n-2,cache)+solve(n-3,cache);
        return cache[n]=ans;
    }
    int tribonacci(int n) {
        vector<int>cache(n+1,-1);
        return solve(n,cache);
    }
};
int main(){
    Solution sol;
    int n=4;
    std::cout << sol.tribonacci(n);
    return 0;
}
