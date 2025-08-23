#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> sum;
        sum[0]=1;
        int count=0;
        int csum=0;
        for (int i=0;i<nums.size();i++){
           csum+=nums[i];
//           if (csum==goal){count++;}
           if (sum.find(csum-goal)!=sum.end()){
                count +=sum[csum-goal];
           }
            sum[csum]++;
        }
        return count;
    }

};
int main (){
    cout << "insert the array \n" ;
    vector <int> nums;
    int x;
    while (cin>>x){
        nums.push_back(x);
        if (cin.peek()=='\n'){
            break;
        }
    }
    cout << "enter the goal" << endl;
    int goal;
    cin >> goal;
    Solution s;
    cout << "the answer is " << s.numSubarraysWithSum(nums,goal);
return 0;
}
