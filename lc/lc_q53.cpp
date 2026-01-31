class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int* arr = &nums[0];
        int numsSize = nums.size();
        int sum = arr[0];
        int max_t = arr[0];
        for (int i = 1; i < numsSize; i++) {
            if (max_t + arr[i] > arr[i]) {
                max_t = max_t + arr[i];
            } else {
                max_t = arr[i];
            }
            if (max_t > sum) {
                sum = max_t;
            }
        }
        return sum;
    }
};
