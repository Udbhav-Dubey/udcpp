#include <bits/stdc++.h>
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> modcount;
        modcount[0]=1;
        int prefixsum=0,count=0;
        for (int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int mod=prefixsum%k;
            if (mod<0) mod=mod+k;
            count +=modcount[mod];
            modcount[mod]++;
        }
        return count;
    }
};
using namespace std;
int main (){
    cout << "please enter the target " << endl;
    int k;
    cin >> k;
    cout << "now lets enter the vector" << endl;
    vector <int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n') break;
    }
    Solution sol;
    cout << "the solution of your problem is " << sol.subarraysDivByK(nums,k);
return 0;
}
