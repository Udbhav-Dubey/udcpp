#include <vector>
using namespace std;
class Solution {
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int x=0;
        int n=isConnected.size();
        vector<bool>visited(n,0);
        for (int i=0;i<n;i++){
            if (visited[i]==false){
                dfs(isConnected,visited,i,n);
                x++;
            }
        }
        return x;
    }
    void dfs(vector<vector<int>>&isConnected,vector<bool>&visited,int i,int n){
        visited[i]=1;
        for (int j=0;j<n;i++){
            if (isConnected[i][j]==1&&visited[j]==false){
                dfs(isConnected,visited,j,n);
            }
        }
    }
};
