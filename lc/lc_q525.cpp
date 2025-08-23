#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> psum;
        int count=0;
        int maxcount=0;
        int sum=0;
        psum[0]=-1;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==0){nums[i]=-1;}
            sum+=nums[i];
            if (psum.find(sum)!=psum.end()){
                count=i-psum[sum];
            }
            if (count>maxcount){
                maxcount=count;
            }
            if (psum.find(sum) == psum.end()) {
            psum[sum] = i;
            }
        }
        return maxcount;
    }
};
int main (){
    vector <int> nums;
    int x;
    cout << "please insert the numbers : ";
    while (cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n'){break;}
    }
    Solution sol;
    cout << "your answer is " << sol.findMaxLength(nums);
return 0;
}
