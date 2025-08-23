#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> nnums;
        nnums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nnums.push_back(nums[i]);
            }
        }
        int count=0;
        for (int i=1;i<nnums.size()-1;i++){
            if (nnums[i]>nnums[i-1] && nnums[i]>nnums[i+1]){count++;}
            if (nnums[i]<nnums[i-1] && nnums[i]<nnums[i+1]){count++;}
        }
        return count++;
    }
};
int main (){
    cout << "please enter the vector : ";
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n'){break;}
    }
    Solution sol;
    cout << "the answer is " << sol.countHillValley(nums);
return 0;
}
