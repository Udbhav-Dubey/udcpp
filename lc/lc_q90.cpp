#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(vector <int> &nums,vector<int> &temp,int index,vector<vector<int>> &result){
        result.push_back(temp);
        for (int i=index;i<nums.size();i++){
            if (i>index && nums[i]==nums[i-1]){continue;}
            temp.push_back(nums[i]);
            backtrack(nums,temp,i+1,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(),nums.end())
        backtrack(nums,temp,0,result);
        return result;
    }
};
int main (){
    vector <int> nums;
    int x;
    cout << "please enter the elements of vector : ";
    while(cin>>x){
        nums.push_back(x);
        if(cin.peek()=='\n') break;
    }
    Solution sol;
    vector <vector <int>> v=sol.subsets(nums);
    for (int i=0;i<v.size();i++){
        for (int j=0;i<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}
