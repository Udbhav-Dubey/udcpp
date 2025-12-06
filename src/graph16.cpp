#include <bits/stdc++.h>
using namespace std;
int minKey(vector<int>&key,vector<bool>&mstSet,int V){
    int minVal=INT_MAX;
    int minIndex=-1;
    for (int v=0;v<V;v++){
        if (!mstSet[v]&&key[v]<minVal){
            minVal=key[v];
            minIndex=v;
        }
    }
    return minIndex;
}
void primMST(std::vector<std::vector<int>>&graph){
    int V=graph.size();
    std::vector<int>parent(V);
    std::vector<int>key(V,INT_MAX);
    vector<bool>mstSet(V,false);
    key[0]=0;
    parent[0]=-1;
    for (int count=0;count<V-1;count++){
        int u=minKey(key,mstSet,V);
        mstSet[u]=true;
        for (int v=0;v<V;v++){
            if (graph[u][v]!=0&&!mstSet[v]&&graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    std::cout << "Edge  Weight\n";
    for (int i=1;i<V;i++){
        std::cout << parent[i] << " - " << i <<"    "<<graph[i][parent[i]]<<"\n";
    }
}
int main (){
    std::vector<std::vector<int>>graph={
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
}
