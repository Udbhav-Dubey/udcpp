#include <vector>
#include <iostream>
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
    for (int i=0;i<adj.size();i++){
        if (visited[i]==false){
            dfsRec(adj,visited,i,res);
        }
    }
    return res;
}
void addEdge(std::vector<std::vector<int>>&adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main (){
    int V=6;
    std::vector<std::vector<int>>adj(V);
    addEdge(adj,1,2);
    addEdge(adj,0,3);
    addEdge(adj,2,0);
    addEdge(adj,5,4);
    std::vector<int>res=dfs(adj);
    for (auto it:res){
        std::cout << it << " ";
    }
    return 0;
}
