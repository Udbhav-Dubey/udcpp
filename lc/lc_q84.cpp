#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> stk;
        int n=heights.size();
        int maxArea=0;
        for (int i=0;i<=n;i++){
            int h=(i==n)?0:heights[i];
            while(!stk.empty()&&heights[stk.top()]>=h){
                int height=heights[stk.top()];
                stk.pop();
                int width=stk.empty()?i;(i-stk.top()-1;)
                int area=heights[temp]*width;
                maxArea=max(maxArea,area);
            }
            stk.push(i);
        }
        return maxArea;
    }
};
int main (){

    return 0;
}
