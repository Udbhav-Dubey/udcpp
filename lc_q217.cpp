#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>um;
        for (int i=0;i<nums.size();i++){
            if (um.find(nums[i])!=um.end()){
                return true;
            }
            um[nums[i]]=i;
        }
        return false;
    }
};
int main (){
vector<int> nums;
int x;
while(cin>>x){
    nums.push_back(x);
    if (cin.peek()=='\n'){
        break;
    }
}
Solution sol;
cout << "the answer is " << sol.containsDuplicate(nums);
return 0;
}
