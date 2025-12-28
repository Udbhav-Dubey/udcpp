class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0]==1||grid[n-1][n-1]==1){
            return -1;
        }
        int steps=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        vector<pair<int,int>>dir8={{1,0},{1,1},{-1,-1},{0,1},{-1,0},{0,-1},{1,-1},{-1,1}};
        while(!q.empty()){
            int len=q.size();
            for (int i=0;i<len;i++){
                auto [i,j]=q.front();
                q.pop();
                if (i==n-1&&j==n-1){return steps;}
                for (auto dir:dir8){
                    auto ni=i+dir.first;
                    auto nj=j+dir.second;
                    if (ni>n-1||nj>n-1||ni<0||nj<0){
                        continue;
                    }
                    if (grid[ni][nj]==0){
                        grid[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
