class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>>adj(s.size());
        for (auto &pair:pairs){
            int u=pair[0];
            int v=pair[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n=adj.size();
        string result=s;
        vector<bool>visited(n,false);    
        for (int i=0;i<n;i++){
            if (visited[i]==false){
                //char temp_c=s[0];
                string temp;
                //temp.push_back(temp_c);
                vector<int>ind;
                dfs(adj,visited,i,temp,ind);    
                sort(temp.begin(),temp.end());
                sort(ind.begin(),ind.end());
                for (int k=0;k<temp.size();k++){
                    result[ind[k]]=temp[k];
                }
            }   
        }
        return result;
    }
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int i,vector<string> &temp,vector<vector<int>>&ind){
        if (visited[i]==1){return ;}
        visited[i]=1;
        char temp_c=s[i];
        temp.push_back(temp_c);
        ind.push_back(i);
        for (auto &j:adj[i]){
            if (visited[j]==false)
            dfs(adj,visited,j,temp,ind);
        }
    }
};
