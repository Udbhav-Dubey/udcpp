#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if (nums[mid]==target){
                return mid;
            }
             if (nums[mid]<=nums[mid]){
                if (nums[mid]<=target && target<nums[mid]){
                    right=mid-1;
                }
                else left=mid+1;
            }
             else {
                if (nums[mid]<target && target<=nums[right]){
                    left=mid+1;
             }
                else{right=mid-1;}
        }
        }
    
        return -1;
    }
};
int main (){
    int x;
    vector<int> vec;
return 0;
}
