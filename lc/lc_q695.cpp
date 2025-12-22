class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        int maxi=0;
        int n=grid.size();
        int nj=grid[0].size();
        for (int i=0;i<n;i++){
            for (int j=0;j<nj;j++){
                if (grid[i][j]==1){
                    count++;
                    int x=dfs(grid,i,j,n,nj);
                    maxi=max(maxi,x);
                }
            }
        }
        return maxi;
    }
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int nj){
        if (i < 0 || i >= n || j < 0 || j >= nj || grid[i][j] != 1)
            return 0;
        grid[i][j]=0;
        int up=dfs(grid,i+1,j,n,nj);
        int down=dfs(grid,i-1,j,n,nj);
        int right=dfs(grid,i,j+1,n,nj);
        int left=dfs(grid,i,j-1,n,nj);
        return up+down+right+left;
    }
};
