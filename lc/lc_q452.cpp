#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       int n=points.size();
       int count=0;
       sort(points.begin(),points.end(),[](vector<int>&x,vector<int>&y){
        return x[1]<y[1];
        });
       for (int i=0;i<n-1;i++){
           int curr=points[i][1];
           while(i<n-1&&curr>=points[i+1][0]&&curr<=points[i][1]){
            count++;
            i++;
           }
       }
       return n-count;
    }
};
int main (){
    Solution sol;
    vector<vector<int>>point1={{10,16},{2,8},{1,6},{7,12}};
    cout << " ans: " << sol.findMinArrowShots(point1);
    return 0;
}
