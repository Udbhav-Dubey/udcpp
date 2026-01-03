class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=queries.size();
        vector<double>answer(n);
        unordered_map<string,vector<pair<string,double>>>adj;
        for (int i=0;i<values.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        for (auto q:queries){
            string src=q[0];
            string dst=q[1];
            if (adj.find(src)==adj.end()||adj.find(dst)==adj.end()){
                answer.push_back(-1.0);
            }
            else {
                unordered_set<string>visited;
                answer.push_back(dfs(src,dst,adj,visited));
            }
        }
        return answer;
    }
double dfs(string curr,string target,unordered_map<string,vector<pair<string,double>>>&adj,unordered_set<string>&visited){
    if (curr==target) return 1.0;
    visited.insert(curr);
    for (auto &edge:adj[curr]){
        string nextNode=edge.first;
        double weight=edge.second;
        if (visited.find(nextNode)==visited.end()){
            double result=dfs(nextNode,target,adj,visited);
            if (result!=-1.0){
                return weight*result;
            }
        }
    }
    return -1.0;
}
};

