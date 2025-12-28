class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    void DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }}

    int find(int x){
        if (parent[x]==x){
            return x;
        }
        else parent[x]=find(parent[x]);
    }
    void unio(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rank[rx]<rank[ry]){
            parent[rx]=ry;
        }
        else if (rank[rx]>rank[ry]){
            parent[ry]=rx;
        }   
        else {
            rank[rx]=rank[ry];
            rank[rx]++;
        }
    }
    }
    struct edge{
        int w;
        int u;
        int v;
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU(n);
        vector<edge>edges;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                struct edge e;
                e.w=wt;
                e.u=i;
                e.v=j;
                edges.push_back(e);
            }
        }
        sort(edges.begin(),edges.end(),[](constEdge &a,constEdge& b){return a.w<b.w;})// how do i put w here 
        int cost=0;
        int used=0;
        for (auto&e:edges){
            if (find(e.u)!=find(e.v)){
                unio(e.u,e.v);
                cost+=e.w;
                used++;
                if (used==n-1){
                    break;
                }
            }
        }
        return cost;
    }
};
