#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(vector<int> &candidates,int index,int target,vector<vector<int>>&result,vector <int>&muller,int sum){
        if (sum>target){return ;}
        if (sum==target){
            result.push_back(muller);
            return;
        }
        for (int i=index;i<candidates.size();i++){
            sum+=candidates[i];
            muller.push_back(candidates[i]);
            backtrack(candidates,i,target,result,muller,sum);
            muller.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector <int> muller;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,target,result,muller,sum);
        return result;
    }
};
int main (){
    cout << "enter the candidates : ";
    int x;
    vector <int> candidates;
    while(cin>>x){
        candidates.push_back(x);
        if (cin.peek()=='\n') {break;}
    }
    int target;
    cout << "enter the target : ";
    cin >> target;
    Solution sol;
    vector<vector<int>> answer=sol.combinationSum(candidates,target);
    for (const auto& row : answer) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
return 0;
}
