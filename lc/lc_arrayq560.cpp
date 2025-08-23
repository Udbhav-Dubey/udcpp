#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;  
    int current_sum = 0;
    int result = 0;

    for (int num : nums) {
        current_sum += num;  
        
        
        if (prefixSumCount.find(current_sum - k) != prefixSumCount.end()) {
            result += prefixSumCount[current_sum - k]; 
        }

        
        prefixSumCount[current_sum]++;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;
    
    int result = subarraySum(nums, k);
    cout << "The number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}

