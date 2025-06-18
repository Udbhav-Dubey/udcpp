#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while (i<=j){
            int sum=numbers[i]+numbers[j];
            if (sum==target){return {i+1,j+1};}
            else if (sum<target){i++;}
            else (j--);
        }
        return {-1,-1};
    }
};
int main(){
    cout << "enter the vector: ";
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n'){break;}
    }
    cout << "enter the target : ";
    int target;
    cin >> target;
    Solution sol;
    vector <int> ans= sol.twoSum(nums,target);
    for (auto it : nums){
        cout << it << " ";
    }
return 0;
}
