class Solution {
public:
    bool hasAlternatingBits(int n) {
        int ctr=-1;
        while(n>=0){
            int rem=n&1;
            if (ctr^rem==0) return false;
            ctr=rem;
            n=n>>1;
    }
        return true;
};
