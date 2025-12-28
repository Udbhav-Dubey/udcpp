#include <bits/stdc++.h>
using namespace std;
int primMst(int n,vector<vector<pair<int,int>>>&adj){
    vector<bool>vis(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    int mst_cost=0;
    while(!pq.empty()){
        auto[wt,node]=pq.top();
        pq.pop();
        if (vis[node])continue;
        vis[node]=true;
        mst_cost+=wt;
        for (auto[nbr,edgewt]:adj[node]){
            if (!vis[nbr]){
                pq.push({edgewt,nbr});
            }
        }
    }
    return mst_cost;
}
int main (){
    int n,m;
    cin>>n,m;
    vector<vector<pair<int,int>>>adj(n);
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({u,w});
        adj[v].push_back({v,w});
    }
    cout << primMst(n,adj)<<"\n";
    return 0;
}
