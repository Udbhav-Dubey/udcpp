#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
        void backtrack(vector<int>&nums,int index,vector <vector<int>> &result){
            if (nums.size()==index){
                result.push_back(nums);
                return ;
            }
            unordered_set<int> used;
            for (int i=index;i<nums.size();i++){
                if (used.count(nums[i])) continue;
                used.insert(nums[i]);
                swap(nums[i],nums[index]);
                backtrack(nums[i],index+1,result);
                swap(nums[i],nums[index]);
            }
        }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <vector <int>> result;
        backtrack(nums,0,result);
    }
};
int main (){
    cout << "please enter the vector elements : ";
    int x;
    vector <int> nums;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    Solution sol;
    vector <vector<int>> v = sol.permutate(nums);
    for (int i=0;i<v.size();i++){
        for (int j=0;i<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
