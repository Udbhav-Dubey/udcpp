class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,string>email_name;
        for (auto &account :accounts){
            string name=account[0];
            string baseMail=account[1];
            for (int i=1;i<account.size();i++){
                string email=account[i];
                email_name[email]=name;
                adj[baseMail].push_back(email);
                adj[email].push_back(baseMail);
            }
        }
        unordered_set<string>visited;
        vector<vector<string>>result;
        for (auto &p:email_name){
            string email=p.first;
            if(visited.count(email))continue;
            vector<string>component;
            dfs(email,adj,visited,component);
            sort(component.begin(),component.end());
            component.insert(component.begin(),emailToName[email]);
            result.push_back(component);
        }
        return result;
    }
    void dfs(const string &email,unordered_map<string,vector<string>>&adj,unordered_set<string>&visited,vector<string>&component){
        visited.insert(email);
        component.push_back(email);
        for (auto &neighbor:adj[email]){
            if (!visited.count[nei]){
                dfs(nei,adj,visited,component);
            }
        }
    }
};
