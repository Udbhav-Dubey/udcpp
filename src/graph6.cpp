#include <iostream>
#include <vector>
std::vector<std::vector<std::pair<int,int>>>createGraph(int V,std::vector<std::vector<int>>&edges){
    std::vector<std::vector<std::pair<int,int>>>adj(V);
    for (auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    return adj;
}
int main (){
    int V = 5;
    std::vector<std::vector<int>> edges = {
        {0, 1, 8},
        {0, 4, 3},
        {1, 2, 6},
        {3, 4, 5}
    };

    std::vector<std::vector<std::pair<int,int>>> adj = createGraph(V, edges);

    std::cout << "Weighted Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        std::cout << i << ": ";
        for (auto &p : adj[i]) {
            std::cout << "(" << p.first << ", w=" << p.second << ") ";
        }
        std::cout << std::endl;
    }
    return 0;
}
