#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int j=0;
        int sum=0;
        int freq=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            j=sum-k;
             if (map.find(j)!=map.end()){
                freq+=map[j];
            }
            map[sum]++;
        }
        return freq;
    }
};
int main (){
cout << "enter the array \n";
vector <int> nums;
int x;
while(cin>>x){
    nums.push_back(x);
    if (cin.peek()=='\n'){
        break;
    }
}
int k;
cout << "please enter the target ";
cin >> k;
Solution sol;
cout << "the answer is " << sol.subarraySum(nums,k);
return 0;
}
