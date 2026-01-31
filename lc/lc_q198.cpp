class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1){return nums[0];}
        if (n==2){return max(nums[0],nums[1]);}
        int a=nums[0];
        int b=nums[1];
        int c=nums[2]+a;
        for (int i=3;i<n;i++){
            int curr=nums[i]+max(b,a);
            a=b;
            b=c;
            c=curr;
        }
        return max(c,b);
    }
};
