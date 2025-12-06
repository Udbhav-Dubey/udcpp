#include <bits/stdc++.h>
using namespace std;
int primMST(int V,vector<vector<pair<int,int>>>&adj){
    vector<bool>visited(V,false);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;
        pq.push({0,0});
        int mst_sum=0;
        while(!pq.empty()){
            auto[wt,node]=pq.top();
            pq.pop();
            if (visited[node])continue;
            mst_sum+=wt;
            visited[node]=true;
            for (auto &p:adj[node]){
                int adjNode=p.first;
                int adjWt=p.second;
                if (!visited[adjNode]){
                    pq.push({adjWt,adjNode});
                }
            }
        }
        return mst_sum;
}
    int main() {
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    cout << primMST(V, adj);
    return 0;
}
