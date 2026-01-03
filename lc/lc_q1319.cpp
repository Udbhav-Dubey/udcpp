#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        vector<int>visited(n,0);
        for (auto &conn: connections){
            int i=conn[0];
            int j=conn[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        //    visited[i]++;
         //   visited[j]++;
        }
        int count=0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                visited[i]=1;
                count++;
                dfs(adj,visited,i);
            }
        }
        return count-1;
    }
void dfs(vector<vector<int>>&adj,vector<int>&visited,int i){
    if (!visited[i]){visited[i]=0;}
    for (int j=0;j<adj[i].size();j++){
        if (!visited[i]){
            dfs(adj,visited,j);
        }
    }
}

};
int main (){
    Solution sol;
    //vector<vector<int>>con=([[0,1],[0,2],[1,2]]);
   return 0; 
}
