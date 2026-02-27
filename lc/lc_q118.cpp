#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
       for (int i=0;i<numRows;i++){
            ans.push_back(vector<int>(i+1));
        }
       ans[0][0]=1;
        for (int i=1;i<numRows;i++){
            for (int j=0;j<=i;j++){
                if (j==0||j==i){
                    ans[i][j]=1;
                }
                else {
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
            }
        }
        return ans;
    }
};
int main (){
    Solution sol;
    int n=5;
    vector<vector<int>>ans=sol.generate(n);
    for (auto x:ans){
        for (auto y:x){
            cout << y << " ";
        }
        cout <<"\n";
    }
    return 0;
}
