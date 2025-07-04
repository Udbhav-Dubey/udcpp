// m1
class Solution {

public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for (auto it : nums){
            sum+=it;
        }
       int expected = n * (n + 1) / 2;
        return expected-sum;
    }
};
// m2 

