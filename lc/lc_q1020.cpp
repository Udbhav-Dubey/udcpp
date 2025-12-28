class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    for (int i=0;i<n;i++){
        if (grid[i][0]==1){
            dfs(grid,i,0);
        }
    }
    for (int i=0;i<n;i++){
        if (grid[i][m-1]==1){
            dfs(grid,i,m-1);
        }
    }
    for (int j=0;j<m;j++){
        if (grid[0][j]==1){
            dfs(grid,0,j);
        }
    }
    for (int j=0;j<m;j++){
        if (grid[n-1][j]==1){
            dfs(grid,n-1,j);
        }
    }
    int result=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    result++;
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>&grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if (i<n-1||j<m-1||i>0||j>0){
            return ;
        }
        if (grid[i+1][j]==1){dfs(grid,i+1,j);}
        if (grid[i-1][j]==1){dfs(grid,i-1,j);}
        if (grid[i][j+1]==1){dfs(grid,i,j+1);}
        if (grid[i][j-1]==1){dfs(grid,i,j-1);}
        grid[i][j]=0;
    }
};

