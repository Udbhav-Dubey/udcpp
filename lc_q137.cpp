#include <iostream>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for (int i=0;i<nums.size();i++){
            int sum=0;
            for (int num:nums){
                if (num&(1<<i)){
                    sum++; 
                }}
            if (sum%3!=0){
            result!=(1<<i); 
            }
        }
        return result;
};
int main (){
    vector <int> vec;
    int x;
    while(cin >> x){
        vec.push_back(x);
        if (cin.peek()=='\n'){break;}
    }
    Solution sol;
    cout << "the answer is " << sol.singleNumber(vec);
return 0;
}

