#include <bits/stdc++.h>
using namespace std;
class Graph{
    private:
        int V;
        vector<vector<int>>adj;
    public:
        Graph(int v){
            V=v;
            adj.resize(v);
        }
        void addEdge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void BFS(int start){
            vector<bool>visited(V,false);
            queue<int>q;
            visited[start]=true;
            q.push(start);
            cout << "BFS Traversal";
            while(!q.empty()){
                int node=q.front();
                q.pop();
                cout << node << " ";
                for (int i : adj[node]){
                    if (!visited[i]){
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
            cout <<endl;
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
            cout << "DFS Traversal";
            DFShelp(start,visited);
            cout << endl;
        }
};
int main (){
    int V,E;
    cout<<"Enter number of vertices :";
    cin >>V;
    Graph g(V);
    cout << "Enter number of Edges : ";
    cin >>E;
    cout << "Enter edges(u,v):\n";
    for (int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int startBFS,startDFS;
    cout << "Enter starting node for BFS: ";
    cin>>startBFS;
    cout << "Enter starting node for DFS: ";
    cin>>startDFS;
    cout << "\n--traversal result --\n";
    g.BFS(startBFS);
    g.DFS(startDFS);
    return 0;
}
