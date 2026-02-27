class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>res(nums.size());
        for (int i=0;i<nums.size();i++){
            if (nums[i]==0){
                res[i]=i;
            }
            else if (nums[i]>0){
                int cur=nums[i]+i;
                cur%=nums.size();
                res[cur]=cur;
            }
            else {
                int cur=nums[i]+i;
                cur%=nums.size();
                res[cur]=cur;
            }
        }
        return res;
    }
};
