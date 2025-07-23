#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        vector<vector<int>> answer;
        for (int i=0;i<nums.size()-2;i++){
            if (i!=0 && nums[i]==nums[i-1]){continue;}
            int j=i+1;
            int k=nums.size()-1;
            while(left<right){
                int total=nums[i]+nums[j]+nums[k];
                if (total==0){
                    answer.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j]==nums[j-1] && j<k){j++;}
                }
                else if (total>0){
                    k--;
                }
                else if (total<0){
                    j++;
                }
            }            
        }
        return answer;
    }
};

int main (){
cout << "please enter the elements of array : ";
int x;
vector<int> nums;
while(cin>>x){
    nums.push_back(x);
    if (cin.peek()=='\n') break;
}
Solution sol;
vector<vector<int>> answer=sol.threeSum(nums);
return 0;
}
