class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int nj=grid[0].size();
        int count=0;
        for (int i=0;i<n;i++){
            for (int j=0;i<nj;i++){
                int s=4;
                if (grid[i][j]==1){
                    if (i<n&&grid[i+1][j]==1){s--;}
                    if (i>0&&grid[i-1][j]==1){s--;}
                    if (j>0&&grid[i][j-1]==1){s--;}
                    if (j<nj&&grid[i][j+1]==1){s--;}
                    count+=s;
                }
            }
        }
        return count;
    }
};  
