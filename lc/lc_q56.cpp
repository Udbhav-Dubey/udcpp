#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int st=intervals[i][0];
            int temp=intervals[i][1];
            while(i<n-1&&temp>=intervals[i+1][0]){
                temp=max(temp,intervals[i+1][1])
                i++;
            }
            vector<int>t={st,temp};
            result.push_back(t);
        }     
        return result;
    }
};
int main (){

    return 0;
}
