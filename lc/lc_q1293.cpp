#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        queue<tuple<int,int,int>>q;
        tuple<int,int,int>t={0,0,0};
        vector<vector<int>>best(m,vector<int>(n,INT_MAX));
        q.push(t);
        best[0][0]=0;
        //grid[0][0]=2;
        vector<pair<int,int>>dir4={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        while(!q.empty()){
            int nq=q.size();
            while(nq--){
            auto [st,i,j]=q.front();
            q.pop();
            if (i==m-1&&j==n-1){return time;}
            for(auto dir:dir4){
                int nj=j+dir.second;
                int ni=i+dir.first;
                int nst=st+grid[i][j];
                if (ni>m-1 || ni <0 || nj>n-1 || nj<0){
                    continue;
                }
                if (nst>k){continue;}
                if (nst>=best[ni][nj]){
                    continue;
                }
                best[ni][nj]=nst;
                q.push({nst,ni,nj});
                }
            }
        
            time++;
    }
        return -1;
    }
};

