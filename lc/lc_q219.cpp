#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int,int> map;
        for (int i=0;i<nums.size();i++){
            if (map.find(nums[i])!=map.end() && i-map[nums[i]]<=k){
                return true;
            }
            if ( i<nums.size()-1 && nums[i]==nums[i+1] && k>=1){return true;}
            map[nums[i]]=i;
        }
        return false;
    }
};
int main (){
    cout << "please enter the vector\n";
    vector <int> nums;
    int x;
    while (cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    cout << "enter the k : ";
    int k;
    cin >> k;
    Solution sol;
    cout << "the answer is " << sol.containsNearbyDuplicate(nums,k);
return 0;
}
