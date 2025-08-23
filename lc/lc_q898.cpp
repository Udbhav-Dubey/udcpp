#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>result,prev;
        for (auto num:arr){
            vector<int> curr;
            curr.insert(num);
            for (auto it : prev){
            int temp=it|num;
            if (curr.back()!=temp)
                curr.push_back(temp;)
            }
            prev=curr;
            result.insert(curr.begin(),curr.end());
        }
        return result.size();
    }
};
int main (){
    int x;
    vector<int> arr;
    while(cin>>x){
        arr.push_back(x);
        if (cin.peek()=='\n') break;
    }
    Solution sol;
    cout << sol.subarrayBitwiseORs(arr);
return 0;
}
