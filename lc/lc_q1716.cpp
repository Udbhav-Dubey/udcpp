class Solution {
public:
    int totalMoney(int n){
        int weeks=n/7;
        int days=n%7;
        int  fweeks=7*weeks*(week+1)/2+21*weeks;
        int rdays=days*(2*(weeks+1)+(days-1))/2;
        return fweeks+rdays;
    } 
};
