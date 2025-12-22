class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc]==color){return image;}
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>>&image,int i,int j,int val,int color){
        if (i<0||j<0||i>=image.size()-1||j>=image[0].size()-1){
            return ;
        }
        if (image[i][j]==val){
            image[i][j]=color;
            dfs(image,i+1,j,val,color);
            dfs(image,i-1,j,val,color);
            dfs(image,i,j+1,val,color);
            dfs(image,i,j-1,val,color);
        }
    }
};
