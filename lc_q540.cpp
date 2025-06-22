#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid =left+(right-left)/2;
            if (mid%2!=0){mid--;}
            if (nums[mid]==nums[mid+1]){
                left=mid+2;
            }
            else {right=mid;}
        }
    return nums[left];
    }
};
int main (){
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n')break;
    }
    Solution sol;
    cout << "the output is " << sol.singleNonDuplicate(nums);
    return 0;
}
