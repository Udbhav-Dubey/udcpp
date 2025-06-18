#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1;
        int last=-1;
        int left=0;
        int right=nums.size()-1;
        while (left<=right){
        int  mid=left+(right-left)/2;
            if (nums[mid]==target){
                first=mid;
                right=mid-1;
            }
            else if (nums[mid]>target){
                right=mid-1;
            }
            else left=mid+1;
        }
        left=0;
        right=nums.size()-1;
         while (left<=right){
           int mid=left+(right-left)/2;
            if (nums[mid]==target){
                last=mid;
                left=mid+1;
            }
            else if (nums[mid]>target){
                right=mid-1;
            }
            else left=mid+1;
        }
        return {first,last};
    }
};
int main (){
    vector <int> nums;
    int x;
    cout << "enter the vector : " ;
    while (cin >> x){
        nums.push_back(x);
        if (cin.peek()=='\n'){break;}
    }
    cout << "please enter the target : ";
    int target;
    cin >> target;
    Solution sol;
    vector <int> result=sol.searchRange(nums,target);
    cout << "result\n";
    for (auto it : result){
        cout << it << " ";
    }
    return 0;
}
