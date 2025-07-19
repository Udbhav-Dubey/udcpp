#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int maxLen=0;
       vector<int> freq(101); // max value in nums is 100

    for (int right = 0; right < nums.size(); right++) {
    freq[nums[right]]++;
    while (freq[nums[right]] > k) {
        freq[nums[left]]--;
        left++;
    }
    maxLen = max(maxLen, right - left + 1);
}

        return maxLen;
    }
};
int main (){
    cout << "please enter the nums vector : ";
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    cout << "please enter the k : ";
    int k;
    cin >> k;
    Solution sol;
    cout << "the answer is " << sol.maxSubarrayLength(nums,k);
return 0;
}
