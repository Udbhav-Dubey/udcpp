#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        vector <int>ans(n,0);
        for (int i=n-1;i>=0;i--){
            int count=0;
            while(!stk.empty()&&heights[i]>heights[stk.top()]){
                stk.pop();
                count++;
            }
            if (!stk.empty()){count++;}
            ans[i]=count;
            stk.push(i);
        }
        return ans;
    }
};
