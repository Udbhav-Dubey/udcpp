class Solution {
public:
    struct State{
        int city;
        int cost;
        int flights;
    };
    const int inf=1e9;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>> adj(n);
       for (auto i : flights){
           int u=i[0];
           int v=i[1];
           int price=i[2];
            adj[u].push_back({v,price});
       }
       vector<vector<int>> best(n,vector<int>(k+2,inf)); 
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,src,0});
        best[src][0]=0;
        while(!pq.empty()){
            auto p=pq.top();
            auto [cost, city, flights] = pq.top();
//            int cost=p.first;
  //          int city=p.second;
    //        int flights=p.third;
            pq.pop();
            if (flights>k+1){
                continue;
            }
            if (cost>best[city][flights]){
                continue;
            }
            for (auto cit:adj[city]){
                int next_city=cit.first;
                int price=cit.second;
                int new_cost=cost+price;
                int new_flights=flights+1;
                if (new_cost<best[next_city][new_flights]){
                    best[next_city][new_flights]=new_cost;
                    pq.push({new_cost,next_city,new_flights});
                }
            }
        }
        int ans=inf;
        for (int f=0;f<=k+1;f++){
            ans=min(ans,best[dst][f]);
        }
        return ans==INF?-1:ans;
    }
};
