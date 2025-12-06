#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph{
    private:
        int V;
        vector<vector<int>>adj;
    public:
        Graph(int vertices){
            V=vertices;
            adj.resize(V);
        }
        void addEdge(int u,int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void printGraph(){
            cout << "Adjancy list representation : \n";
            for (int i=0;i<V;i++){
                cout << i << "->";
                for (int neighbor:adj[i]){
                    cout << neighbor << " ";
                }
                cout << endl;
            }
        }
void BFS(int start){
    vector<bool>visited(V,false);
    queue<int>q;
    visited[start]=true;
    q.push(start);
    cout << "BFS Traversal starting from " << start << " : ";
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor:adj[node]){
            if (!visited[neighbor]){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
void DFS(int start){
    vector<b`>
}
};
int main (){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.printGraph();
    g.BFS(0);
    return 0;
}
