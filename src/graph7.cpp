// BFS from a Given Source in an Undirected Graph:
#include <iostream>
#include <vector>
#include <queue>
std::vector<int>bfs(std::vector<std::vector<int>>&adj){
    int V=adj.size();
    std::vector<bool>visited(V,false);
    std::vector<int>res;
    std::queue<int>q;
    int src=0;
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
    return res;
}
void addEdge(std::vector<std::vector<int>>&adj,int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main (){
    int V=5;
    std::vector<std::vector<int>>adj(V);
    addEdge(adj,1,2);
    addEdge(adj,1,0);
    addEdge(adj,2,0);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    std::vector<int>res=bfs(adj);
    for (int i:res){
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
