#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> answer(nums.size());
        int m=1;
        int zc=0;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]==0){
                zc++;
                if (zc>1){break;}
                else continue;}
                 m*=nums[i];
        }
        for (int i=0;i<nums.size();i++){
            if (zc==1){
                if (nums[i]==0){answer[i]=m;}
                else answer[i]=0;
            };
            if (zc==0){answer[i]=m/nums[i];}
            if (zc>1){answer[i]=0;}
        }
        return answer;
    }   
};
int main (){
    vector <int> nums;
    int x;
    while (cin>>x){
        nums.push_back(x);
        if(cin.peek()=='\n') {break;}
    }
    Solution sol;
    vector<int> answer=sol.productExceptSelf(nums);
    for (auto it : answer){
        cout << it << " ";
    }
return 0;
}
