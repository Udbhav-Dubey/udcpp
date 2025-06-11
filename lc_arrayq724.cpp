#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        
        int preleft = 0; 
        
        for (int mid = 0; mid < size; mid++) {
            int preright = totalSum - preleft - nums[mid];
            
            if (preleft == preright) {
                return mid;
            }
            
            preleft += nums[mid];
        }
        
        return -1;
    }
};


return 0;
}
