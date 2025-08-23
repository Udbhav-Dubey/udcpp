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
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorAll = 0, xorNums = 0;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            xorAll ^= i;
        }
        for (int num : nums) {
            xorNums ^= num;
        }
        return xorAll ^ xorNums;
    }
};

