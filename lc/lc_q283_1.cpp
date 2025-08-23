#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
int main (){
    vector <int> nums;
    int x;
    cout << "fill the vector : ";
    while (cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n')break;
    }
    Solution sol;
    sol.moveZeroes(nums);
    for (auto it:nums){cout << it << " ";}
return 0;
}
