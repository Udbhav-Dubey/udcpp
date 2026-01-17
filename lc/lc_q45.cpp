class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int i=0;
        int right=0;
        int mj=0;
        int mx=0;
        while(i<n-1){
            count++;
            for (int j=mj;j<=right;i++){
                i=max(i,j+nums[j]);
            }
            mj=right+1;
            right=i;
        }
        return count;
    }
};

