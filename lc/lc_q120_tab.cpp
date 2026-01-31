#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int inf=1e9;
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=triangle.size()-2;i>=0;i--){
            for (int j=0;j<triangle[i].size();j++){
                int b1=triangle[i+1][j];
                int b2=triangle[i+1][j+1];
                triangle[i][j]+=min(b1,b2);
            }
        }
        return triangle[0][0];
    }
};
int main (){
Solution sol;
vector<vector<int>>triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
cout << sol.minimumTotal(triangle);
return 0;
}
