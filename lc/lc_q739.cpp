#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector <int> ans(n,0);
        stack <int> stk;
        for (int i=0;i<n;i++){
            while(!stk.empty()&&temperatures[i]>temperatures[stk.top()]){
                ans[stk.top()]=(i-stk.top());
                stk.pop();
            }
                stk.push(i);
        }
        return ans;
    }
};
int main (){
Solution sol;
vector <int> temperatures={89,62,70,58,47,47,46,76,100,70};
vector <int> answer=sol.dailyTemperatures(temperatures);
for (int i : answer){
    cout << i << " ";
}
return 0;
}
