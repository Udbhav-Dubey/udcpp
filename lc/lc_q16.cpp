#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()==3){return nums[0]+nums[1]+nums[2];}
        sort(nums.begin(),nums.end());
        int mini=target-(nums[0]+nums[1]+nums[2]);
        if (mini<0){mini=-mini;}
        int cdistance=0;
        bool b=0;
        bool bb=0;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int total=nums[i]+nums[j]+nums[k];
                if (total==target){return total;}
                else if (total>target){
                k--;
                b=0;
                cdistance=total-target;
                }
                else {
                j++;
                b=1;
                cdistance=target-total;
                }
                if (cdistance<=mini){
                    bb=b;
                    mini=cdistance;
                }
            }
        }
        if (bb==1){return target-mini;}
        else return target+mini;
    }
};

int main (){
    vector<int>num;
    int x;
    while(cin>>x){
        num.push_back(x);
        if (cin.peek()=='\n') break;
    }
    int target;
    cout << "target : ";
    cin >> target;
    Solution sol;
    cout << "answer is :" << sol.threeSumClosest(num,target);
return 0;
}
