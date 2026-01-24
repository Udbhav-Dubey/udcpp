class Solution {
public:
    int solve(int n,vector<int>&cache){
        if (n==0){return 0;}
        else if (n==1){return 1;}
        if (cache[n]!=-1){
            return cache[n];
        }
        cache[n]=solve(n-1,cache)+solve(n-2,cache);
        return cache[n];
    }
    int fib(int n) {
        //if (n==0){return 0;}
        //else if (n==1){return 1;}
        vector<int>cache(n+1,-1);
        return solve(n,cache);
                
    }
};
