class Solution {
public:
    int hammingWeight(int n) {
       int ctr=0;
       while(n!=0){
        if(num&1){
        ctr++;
            }
        n=n>>1
       }
       return ctr;
    }
};
