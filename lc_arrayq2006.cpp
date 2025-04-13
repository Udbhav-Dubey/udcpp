#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i=;i<nums.size();i++){
            int low = nums[i] - k;
    int high = nums[i] + k;

    if (freq.find(low) != freq.end()) {
    count += freq[low];
}
    if (k != 0 && freq.find(high) != freq.end()) {
    count += freq[high];
}
    freq[nums[i]]++;

        }
return count;
    }
};
