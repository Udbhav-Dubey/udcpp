class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int countZero = 0;
        for (int& num : nums) {
            if (num % 2 == 0) countZero++;
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i < countZero ? 0 : 1;
        }

        return nums;
    }
};
