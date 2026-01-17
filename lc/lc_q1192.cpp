#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n==2){return connections ;}
        vector<vector<int>>adj(n);
        for (auto &c:connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector<bool>visited(n,false);
        return adj;
    }
};
int main (){
    Solution sol;
    vector<vector<int>>connections={{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>>ans=sol.criticalConnections(4,connections);
    for (auto a:ans){
        cout << "[" << a[0] << "," << a[1] << "]\n";
    }
    return 0;
}
