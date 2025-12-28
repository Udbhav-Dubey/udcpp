#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>answer;
        if (n==1){answer.push_back(0);return answer; }
        vector<int>degree(n,0);
        vector<vector<int>>adj(n);
        for (auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            degree[u]++;
            degree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    queue<int>q;
    for(int i=0;i<n;i++){
        if (degree[i]==1){
            q.push(i);
        }
    }
    int remaining=n;
    while(remaining>2){
        int len=q.size();
        remaining-=len;
        for (int i=0;i<len;i++){
            int temp=q.front();
            q.pop();
            degree[temp]--;
            for (auto i:adj[temp]){
                degree[i]--;
                if (degree[i]==1){q.push(i);}
            }
        }
    }
    while(!q.empty()){
        answer.push_back(q.front());
        q.pop();
    }
    return answer;
    }
    };

int main() {
    Solution sol;

    {
        int n = 4;
        vector<vector<int>> edges = {
            {1, 0},
            {1, 2},
            {1, 3}
        };
        auto ans = sol.findMinHeightTrees(n, edges);
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }

    {
        int n = 6;
        vector<vector<int>> edges = {
            {3, 0},
            {3, 1},
            {3, 2},
            {3, 4},
            {5, 4}
        };
        auto ans = sol.findMinHeightTrees(n, edges);
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }

    {
        int n = 1;
        vector<vector<int>> edges;
        auto ans = sol.findMinHeightTrees(n, edges);
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

