class Solution {
public:
    void backtrack(vector <int>&nums,int index,vector <vector<int>> &result){
        if (index==nums.size()){
            result.push_back(nums);
            return;
        }
        for (int i = index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            backtrack(nums,index+1,result);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> result;
        backtrack(nums,0,result);
        return result;
    }
};
