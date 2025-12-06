// adjaceny matrix rep for undirected 
#include <iostream>
#include <vector>
std::vector<std::vector<int>>createGraph(int V,std::vector<std::vector<int>>&edges){
    std::vector<std::vector<int>>mat(V,std::vector<int>(V,0));
    for (auto&it:edges){
        int u=it[0];
        int v=it[1];
        mat[u][v]=1;
        mat[v][u]=1; // undirected graph 
    }
    return mat;
}
int main (){
    int V=3;
    std::vector<std::vector<int>>edges={{0,1},{0,2},{1,2}};
    std::vector<std::vector<int>>mat=createGraph(V,edges);
    std::cout << "Adjacency Matrix Representation :" << std::endl;
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            std::cout << mat[i][j]<<" ";
        }
        std::cout << std::endl;
    }
    return 0;
}
