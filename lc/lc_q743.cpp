#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int inf=1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int cost=0;
        vector<int>dist(n,inf);
        vector<vector<pair<int,int>>>adj(n);
        for (auto &t:times){
            int u=t[0]-1;
            int v=t[1]-1;
            int w=t[2];
            adj[u].push_back({v,w});
        }
        dist[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k-1});
        while(!q.empty()){
            auto[d,u]=q.top();
            q.pop();
            if (d>dist[u]){continue;}

            for (auto &p:adj[u]){
                int wt=p.second;
                int v=p.first;
                if (dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    q.push({dist[v],v});
                }
            }
        }
        for (auto dis:dist){
            if (dis==inf){return -1;}
            cost=max(cost,dis);
        }
         return cost;
    }
};
#include <bits/stdc++.h>
using namespace std;

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> times1 = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int n1 = 4, k1 = 2;
    cout << sol.networkDelayTime(times1, n1, k1) << endl; // Expected: 2

    // Example 2
    vector<vector<int>> times2 = {
        {1, 2, 1}
    };
    int n2 = 2, k2 = 1;
    cout << sol.networkDelayTime(times2, n2, k2) << endl; // Expected: 1

    // Example 3
    vector<vector<int>> times3 = {
        {1, 2, 1}
    };
    int n3 = 2, k3 = 2;
    cout << sol.networkDelayTime(times3, n3, k3) << endl; // Expected: -1

    return 0;
}

