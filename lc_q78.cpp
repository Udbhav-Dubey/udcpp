#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
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
    
return 0;
}
