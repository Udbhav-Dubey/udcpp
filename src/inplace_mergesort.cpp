#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mergeInPlace(vector<int>& nums, int l, int m, int r) {
        int start1 = l, start2 = m + 1;

        while (start1 <= m && start2 <= r) {
            if (nums[start1] <= nums[start2]) {
                start1++;
            } else {
                int value = nums[start2];
                int index = start2;

                // Shift all elements between start1 and start2 right by one
                while (index != start1) {
                    nums[index] = nums[index - 1];
                    index--;
                }

                nums[start1] = value;

                // Update all pointers
                start1++;
                m++;
                start2++;
            }
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r - l) / 2;

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        mergeInPlace(nums, l, m, r);
    }

    void sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {5, 2, 3, 1, 4, 6};
    Solution sol;
    sol.sortArray(nums);

    cout << "Sorted array (in-place merge sort): ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

