class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            int left = (mid == 0) ? INT_MAX : nums[mid - 1];
            int right = (mid == nums.size() - 1) ? INT_MAX : nums[mid + 1];

            if (nums[mid] < left && nums[mid] < right) {
                return nums[mid];
            }

            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return nums[start];
    }
};

