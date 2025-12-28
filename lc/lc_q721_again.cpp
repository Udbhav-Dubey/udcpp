#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>>mail_linkage;
        unordered_map<string,string>nameTOmail;
        for (auto &account:accounts){
            string name=account[0];
            string first_mail=account[1];
//            string result;
            for (int i=1;i<account.size();i++){
                string mail=account[i];
            nameTOmail[first_mail]=name;
            mail_linkage[first_mail].push_back(mail);
            mail_linkage[mail].push_back(first_mail);
                //result.push_back(mail);
                //mail_linkage[result]=accounts;
            }
        }
        vector<vector<string>>answer;
        unordered_set<string> visited;
        for (auto &p:nameTOmail){
            string email=p.first;
            if (!visited.count(email)){
            vector<string>component;
            dfs(email,component,visited,mail_linkage);
            sort(components.begin(),componets.end());
            component.insert(component.begin(),emailTOname[email]);
            answer.push_back(component);
        }
        }
   
    return answer ;
}
    void dfs(string &email,string &component,unordered_set<string>&visited,unordered_map<string,vector<string>>&mail_linkage){
        visited.insert(email);
        component.push_back(email);
        for (auto &neighbor:mail_linkage[email]){
            if (!visited.count(neighbor)){
                dfs(neighbor,component,visited,mail_linkage);
            }
        }
        } 
};
