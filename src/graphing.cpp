#include <bits/stdc++.h>
using namespace std;
class Graph{
private:
    vector<vector<int>>adj;
    int V;
public:
    Graph(int v){
        V=v;
        adj.resize(v);
    }
    void addedge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int start){
        vector<bool>visited(V,false);
        queue<int>q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout << node << " ";
            for (int neigh:adj[node]){
                if (!visited[neigh]){
                    visited[neigh]=true;
                    q.push(neigh);
                }
            }
        }
        cout << "\n";
    }
    void DFShelp(int node,vector<bool>&visited){
        visited[node]=true;
        cout << node << " ";
        for (int n:adj[node]){
            if (!visited[n]){
                DFShelp(n,visited);
            }
        }
    }
    void DFS(int start){
        vector<bool>visited(V,false);
        cout << "DFS travel : ";
        DFShelp(start,visited);
        cout << endl;
    }
};

    int main() {
    Graph g(5);   // create a graph with 5 nodes: 0,1,2,3,4

    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(2, 4);

    cout << "BFS traversal: ";
    g.BFS(0);

    cout << "DFS traversal: ";
    g.DFS(0);

    return 0;
}
