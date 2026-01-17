#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dir_4={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>q;
        q.push({grid[0][0],0,0});
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=1;
        while(!q.empty()){
                auto [time,i,j]=q.top();
                q.pop();
                if (i==n-1&&j==n-1){return time;;}
                for (auto dir:dir_4){
                    int ni=dir[0]+i;
                    int nj=dir[1]+j;
                    if(ni<0 || ni>n-1 || nj<0 || nj>n-1){
                        continue;
                    }
                    if (visited[ni][nj]==1){continue;}
                        visited[ni][nj]=1;
                        q.push({max(time,grid[ni][nj]),ni,nj});
                    
                }
            }
        return -1;
    }
};
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {0, 2},
        {1, 3}
    };
    cout << sol.swimInWater(grid1) << endl; // expected: 3

    vector<vector<int>> grid2 = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };
    cout << sol.swimInWater(grid2) << endl; // expected: 16

    return 0;
}
