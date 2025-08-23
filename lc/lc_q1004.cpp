#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int z_ctr=0;
        int max=0;
        for (int right=0;right<nums.size();right++){
            if (nums[right]==0){z_ctr++;}
            while(z_ctr>k){
                if (nums[left]==0){z_ctr--;}
                left++;
            }
            int current=right-left+1;
            (current>max) ? max = current:1;
        }
        return max;
    }
};
int main (){
    cout << "please enter the values : ";
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    int k;
    cout << "please enter the target : ";
    cin >> k;
    Solution sol;
    cout << "the max consecutive one is " << sol.longestOnes(nums,k);
return 0;
}   
