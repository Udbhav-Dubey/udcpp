#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>parents;
    vector<int>ranks;
    void DSU(int n){
        parents.resize(n);
        ranks.resize(n);
        for (int i=0;i<n;i++){
            parents[i]=i;
            ranks[i]=0;
        }
    }
    int parent(int x){
        if (parents[x]==x){return x;}
        else return parents[x]=parent(x);
    }
    void unite(int x,int y){
        int rx=parent(x);
        int ry=parent(y);
        if (ranks[rx]>ranks[ry]){
            ranks[ry]=ranks[rx];
        }
        else if (ranks[ry]<ranks[rx]){
            ranks[rx]=ranks[ry];
        }
        else {
            ranks[rx]=ranks[ry];
            rank[rx]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n-1>connections.size()){
            return -1;
        }
        int count=0;
        for (auto &con:connections){
            int u_p=parent(con[0]);
            int v_p=parent(con[1]);
            if (u_p!=v_p){
                unite(u_p,v_p);
                count--;
            }
        }
        return n-count-1;
    }
};
