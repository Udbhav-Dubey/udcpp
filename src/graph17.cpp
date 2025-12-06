#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,std::vector<std::vector<int>>adj[]){
    std::priority_queue<std::pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    std::vector<bool>vis(V,false);
    int mstSum=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto[wt,node]=pq.top();
        pq.pop();
        if (vis[node])continue;
        vis[node]=true;
        mstSum+=wt;
        for(auto&it:adj[node]){
            int adjNode=it[0];
            int adjWt=it[1];
            if (!vis[adjNode]){
                pq.push({adjWt,adjNode});
            }
        }
    }
    return mstSum;
}
int main (){
    int V=3;
    std::vector<std::vector<int>> edges = {
        {0,1,5},
        {1,2,3},
        {0,2,1}
    };
    std::vector<std::vector<int>>adj[V];
    for (auto &e:edges){
        int u=e[0],v=e[1],w=e[2];
        adj[u].push_back({v,w});
        adj[u].push_back({u,w});
    }
    std::    cout << spanningTree(V,adj);
}
