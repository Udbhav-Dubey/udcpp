class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        int count = 1, maxCount = 1;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i] - 1) {
                count++;
                maxCount = max(count, maxCount);
            } else if (nums[i - 1] != nums[i]) {
                count = 1;
            }
        }
        return maxCount;
    }
};
