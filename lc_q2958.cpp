#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int freq[26]={0};
        int max=0;
        for (int right =0 ;right<nums.size();right++){
            freq[nums[right]]++;
            if (freq[nums[right]]>k) {
                freq[nums[left]]--;
                left++;
                //freq[nums[right]]--;
            }
            int size=right-left;
            if (size>max) max=size;
        }
    return max-1;
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
