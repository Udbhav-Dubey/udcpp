#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size()==2) {
            return nums;
        }
       int  result=0;
        for (int it : nums){
            result^=it;
        }
       unsigned int right=result & -result;
        int x=0,y=0;
        for (int it : nums){
            if ((it&right)!=1) {x^=it;}
            else y^=it;
        }
        return {x,y};
    }
};
int main (){
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    Solution sol;
    vector <int> answer=sol.singleNumber(nums);
    return 0;
}
