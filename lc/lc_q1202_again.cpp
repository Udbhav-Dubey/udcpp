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
        string result=s;
        vector<bool>visited(s.size(),false);
        for (int i=0;i<s.size();i++){
            if (visited[i]!=1){
                string temp;
                vector<int>tmp;
                dfs(adj,visited,i,s,temp,tmp);
                sort(temp.begin(),temp.end());
                sort(tmp.begin(),tmp.end());
                for (int k=0;k<temp.size();k++){
                    result[tmp[k]]=temp[k];
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int i,string &s,string &temp,vector<int>&tmp){
        if (visited[i]==1){return ;}
        visited[i]=1;
        temp.push_back(s[i]);
        tmp.push_back(i);
        for (auto j:adj[i]){
            if (visited[j]!=1){
                dfs(adj,visited,j,s,temp,tmp);
            }
        }
    }
};
