#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(vector <int>&nums,int sum,int k,int n,int index,vector<vector<int>> &result){
        if (sum>n){return ;}
        if (nums.size()==k && sum==n){
            result.push_back(nums);
            return ;
        }
        for (int i=index;i<=9;i++){
            nums.push_back(i);
            sum+=i;
            backtrack(nums,sum,k,n,i+1,result);
            nums.pop_back();
            sum-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <vector<int>> result;
        vector <int> nums;
        int sum=0;
        backtrack(nums,sum,k,n,1,result);
        return result;
    }
};
int main (){
    cout << "please enter the k :" ;
    int k;
    cin >> k;
    cout << "please enter the n : ";
    int n;
    cin >> n;
    Solution sol;
    vector<vector<int>> answer=sol.combinationSum3(k,n);
    for (const auto&row : answer){
        for (int val:row){
            cout << val << " ";
        }
        cout << endl;
    }
return 0;
}
