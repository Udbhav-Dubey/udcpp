#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for (int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]!=x){
                parent[x]=find(parent[x]);}
            return parent[x];
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rx==ry){
            return ;
        }
        if (rank[rx]<rank[ry]){
            parent[rx]=ry;
        }
        else if (rank[rx]>rank[ry]){
            parent[ry]=rx;
        }
        else {
            parent[ry]=rx;
            rank[rx]++;
        }
    }
};
int kruskalMST(int n,vector<vector<int>>&edges){
    sort(edges.begin(),edges.end(),[](auto&a,auto&b){return a[2]<b[2];});
    DSU dsu(n);
    int mstWeight=0;
    vector<vector<int>>mstEdges;
    for (auto&e:edges){
        int u=e[0];
        int v=e[1];
        int w=e[2];

        if (dsu.find(u)!=dsu.find(v)){
            dsu.unite(u,v);
            mstWeight+=w;
            mstEdges.push_back(e);
        }
    }
    cout << "Edges in MST:\n";
    for (auto&e:mstEdges){
        cout << e[0] << "------" << e[1] <<"(weight  " << e[2] << ")\n";
    }
    return mstWeight;
}
int main() {
    // Example graph
    vector<vector<int>> edges = {
        {1, 2, 1},
        {1, 4, 2},
        {2, 4, 3},
        {1, 3, 4},
        {3, 4, 5}
    };

    int n = 4; // number of vertices

    int result = kruskalMST(n, edges);
    cout << "Total MST Weight = " << result << endl;

    return 0;
}

