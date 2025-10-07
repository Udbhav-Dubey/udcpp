#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(n,-1);
        stack <int> stk;
        for (int i=0;i<2*n;i++){
            int cur=nums[i%n];
            while(!stk.empty()&&nums[stk.top()]<cur){
                ans[stk.top()]=cur;
                stk.pop();
            }
            if (i<n) stk.push(i); // pheli baar mein hi push karna hai dusre mein sirf check
        }
        return ans;
    }
};
int main (){
    vector <int>nums={1,2,1};
    Solution sol;
    vector <int>answer=sol.nextGreaterElements(nums);
    for (int num:answer){
        cout << num << " " << endl;
    }
    return 0;
}
