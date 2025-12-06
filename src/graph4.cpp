// adjancey list for undirected 
#include <vector>
#include <iostream>
std::vector<std::vector<int>>createGraph(int V,std::vector<std::vector<int>>&edges){
    std::vector<std::vector<int>>adj(V);
    for (auto &it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);//undirected 
    }
    return adj;
}
int main (){
    int V=3;
    std::vector<std::vector<int>>edges={{0,1},{0,2},{1,2}};
    std::vector<std::vector<int>>mat=createGraph(V,edges);
    std::cout << "Adjancey list : \n";
    for (int i=0;i<V;i++){
        std::cout << i << ": ";
        for (int j:mat[i]){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
