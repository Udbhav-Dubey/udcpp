#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right =nums.size()-1;
        int found=-1;
        while (left<=right){
        int mid=left+(right-left)/2;
            if (nums[mid]==target){
                found=mid;
                break;
            }
            else if (nums[mid]>target){
                right=mid-1;
            }
            else left=mid+1;
        }
        if (found == -1) return {-1, -1};
        left=found;
        right =found;
        while (left >0 && nums[left-1]==target){
            left--;
        }
        while (right < nums.size()-1 && nums[right+1]==target){
            right++;
        }
        return {left,right};
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
