class Solution {
public:
    vector<int>parents;
    vector<int>ranks;
    DSU(int n){
        parents.resize(n);
        ranks.resize(n);
        for (int i=0;i<n;i++){
            parents[i]=i;
            ranks[i]=0;
        }
    }
    int find(int x){
        if (parents[x]==x){
            return x;
        }
        return parents[x]=find(parents[x]);
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rx==ry){return ;}
        if (ranks[rx]>ranks[ry]){
            parent[ry]=rx;
        }
        else if (ranks[rx]<ranks[ry]){
            parent[rx]=ry;
        }
        else {
            ranks[ry]=rx;
            ranks[rx]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DSU(n);
        for (auto &[u,v]:pairs){
            unite(u,v);
        }
        unordered_map<int,vector<char>>components;
        for (int i=0;i<n;i++){
            components[find(i)].push_back(s[i]);
        }
        for (auto &it:components){
            sort(it.first.begin(),it.second.end(),greater<char>());
        }
        for (int i=0;i<n;i++){
            int root=find(i);
            s[i]=components[root].back();
            components[root].pop_back();
        }
        return s;
    }
};
