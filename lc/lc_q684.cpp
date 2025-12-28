class Solution {
public:
    std::vector<int>parent;
    std::vector<int>rank;
    void Dsu(int n){
        parent.resize(n);
        rank.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if (parent[x]==x){
            return x;
        }
        else return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rx==ry){return ;}
        if (rank[rx]<rank[ry]){
            parent[rx]=ry;
        }
        else if (rank[ry]<rank[rx]){
            parent[ry]=rx;
        }
        else {
            parent[ry]=rx;
            rank[rx]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Dsu(n);
        vector<int>result(2);
        for (auto &edge:edges){
            int i=edge[0];
            int j=edge[1];
                i--;
                j--;
                if (find(i)==find(j)){
                    return edge;
                }
                else unite(i,j);
            }
        }
        return result;
    }
};
