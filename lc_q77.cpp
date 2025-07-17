#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(vector <int> &nums,int index,int n,int k ,vector<vector<int>> &result){
            if ((nums.size())==k){
                result.push_back(nums);
                return ;
            }
        for (int i=index;i<=n;i++){
            nums.push_back(i);
            backtrack(nums,i+1,n,k,result);
            nums.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> nums;
        backtrack(nums,1,n,k,result);
        return result;
    }
};
int main (){
    int n,k;
    cout << "enter the n : ";
    cin >> n;
    cout << "enter the k : ";
    cin >> k;
    Solution sol;
    vector <vector<int> answer=sol.combine(n,k);
    for (const auto& row : answer) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
return 0;
}
