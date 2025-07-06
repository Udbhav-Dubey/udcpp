class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=left+1;
        int resi=left;
        int resj=right;
        int j=right-1;
        while(j>i){
            resi&=i;
            resj&=j;
            i++;
            j--;
        }
        return resi&resj;
    }
};
