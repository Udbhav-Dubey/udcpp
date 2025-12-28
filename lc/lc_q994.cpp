class Solution {
private:
    int fresh_ones=0;
public:
    void rot_them(vector<vector<int>>&grid,int i ,int j,bool &spread,queue<pair<int,int>>&q){
        grid[i][j]=2;
        spread=true;
        q.push((i,j));
        fresh_ones--;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int nj=grid[0].size();
        int time=0;
        queue<pair<int,int>> q;
        for (int i=0;i<n;i++){
            for (int j=0;j<nj;j++){
                if (grid[i][j]==1){fresh_ones++;}
                if (grid[i][j]==2){
                    q.push((i,j));
                }
            }
        }
        while(!q.empty()){
            int len=q.size();
            bool spread=false;
            for (int u=0;u<len;u++){
                 pair<int,int> p=q.front();
                 q.pop();
                 int i=q.first();
                 int j=q.second();
                 if (i<n-1&&grid[i+1][j]==1){rot_them(grid,i+1,j,spread,q);}
                 if (i>0&&grid[i-1][j]==1){rot_them(grid,i-1,j,spread,q);}
                 if (j<nj-1&&grid[i][j+1]==1){rot_them(grid,i,j+1,spread,q);}
                 if (j>0&&grid[i][j-1]==1){rot_them(grid,i,j-1,spread,q);}
            }
            if (spread==true){time++;}
        }
        if (fresh_ones>0){return -1;}
        else {
        return time;}
    }
};
