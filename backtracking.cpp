#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            cout << "Permutation: ";
            for (int n : nums) cout << n << " ";
            cout << endl;
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            cout << "Swapping index " << index << " and " << i << ": ";
            swap(nums[i], nums[index]);
            for (int n : nums) cout << n << " ";
            cout << endl;

            backtrack(nums, index + 1);  

            swap(nums[i], nums[index]); 
            cout << "Backtracking (undo swap at index " << index << " and " << i << "): ";
            for (int n : nums) cout << n << " ";
            cout << endl;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    sol.permute(nums);
    return 0;
}

