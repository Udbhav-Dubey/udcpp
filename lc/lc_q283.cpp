#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0;i<nums.size()-1;i++){
            if (nums[i]==0){
               int j;
               // nums[i]=nums[j+1];
                for (j=i;j<nums.size()-1;j++){
                    nums[j]=nums[j+1];
                }
                nums[nums.size()-1]=0;
            }
            else continue;
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
