#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void backtrack(vector <int> & nums,int index,vector<vector<int>> &result){
        if (index==nums.size()){
            result.push_back(nums);
            return ;
        }
        for (int i=index;i<nums.size();i++){
            if (i!=index&&nums[i]==nums[index]) continue;
            swap(nums[i],nums[index]);
            backtrack(nums,index+1,result);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        backtrack(nums,0,result);
        return result;
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
