#include <iostream>
#include <vector>
void dfsRec(std::vector<std::vector<int>>&adj,std::vector<bool>&visited,int s,std::vector<int>&res){
    visited[s]=true;
    res.push_back(s);
    for (int i:adj[s]){
        if (visited[i]==false){
            dfsRec(adj,visited,i,res);
        }
    }
}
std::vector<int>dfs(std::vector<std::vector<int>>&adj){
    std::vector<bool>visited(adj.size(),false);
    std::vector<int>res;
    dfsRec(adj,visited,0,res);
    return res;
}
void addEdge(std::vector<std::vector<int>>&adj,int u,int v){
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
    std::vector<int>res=dfs(adj);
    for (int i=0;i<V;i++){
        std::cout << res[i] << " ";
    }
    return 0;
}
