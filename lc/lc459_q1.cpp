class Solution {
public:
    bool checkDivisibility(int n) {
        int sumi=0;
        int multi=1;
        while(n>0){
            int dig=n%10;
            sumi+=dig;
             multi*=dig;
            n=n/10;
        }
        int final2= sumi +multi
        if (final2%n==0){return true;}
        return false;
    }
};©leetcode
