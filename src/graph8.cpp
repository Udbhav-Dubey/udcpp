//BFS of a Disconnected Undirected Graph
#include <iostream>
#include <queue>
#include <vector>
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfsConnected(std::vector<std::vector>&adj,int src,std::vector<bool>&visited,std::vector<int>&res){
    std::queue<int>q;
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for (int x:adj[curr]){
            if (!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
std::vector<int>bfs(std::vector<std::vector<int>>&adj){
    int V=adj.size();
    std::vector<bool>visited(V,false);
    std::vector<int>res;
    for (int i=0;i<V;i++){
        if (!visited[x]){
            bfsConnected(adj,i,visited,res);
        }
    }
    return res;
}
int main (){
    int V = 6;
    vector<vector<int>> adj(V);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 5, 4);
    std::vector<int> res = bfs(adj);
    for (int i : res)
        std::cout << i << " ";
    return 0;
}
