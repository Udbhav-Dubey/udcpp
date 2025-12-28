class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int mst_cost=0;
        int n=points.size();
        vector<bool>visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto[wt,u]=pq.top();
            pq.pop();
            if (visited[u]){continue};
            visited[u]=1;
            mst_cost=wt;
            for (int i=0;i<n;i++){
                if (!visited[i]){
                    int dist=abs((points[u][0]-points[i][0])+points[u][1]-points[v][1]);
                    pq.push({dist,v});
                }
            }
        }
        return mst_cost;
    }
};
