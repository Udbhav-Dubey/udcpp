// weighted graph && directed 
#include <iostream>
#include <vector>
std::vector<std::vector<int>>createWeightedGraph(int V,std::vector<std::vector<int>>&edges){
    std::vector<std::vector<int>>mat(V,std::vector<int>(V,-1));
    for (auto&it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        mat[u][v]=w;
    }
    return mat;
}
int main (){
    int V=3;
    std::vector<std::vector<int>> edges = {
        {0, 1, 8},
        {0, 2, 3},
        {1, 2, 6}
    };

    std::vector<std::vector<int>> mat = createWeightedGraph(V, edges);

    std::cout << "Weighted Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::   cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

