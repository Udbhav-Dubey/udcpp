#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Left pass (prefix product)
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Right pass (suffix product)
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    vector<int> nums;
    int x;
    cout << "Enter numbers: ";
    while (cin >> x) {
        nums.push_back(x);
        if (cin.peek() == '\n') break;
    }

    Solution sol;
    vector<int> answer = sol.productExceptSelf(nums);

    cout << "Output: ";
    for (int it : answer) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

