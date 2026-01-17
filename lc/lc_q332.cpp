#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>graph;
    vector<string>result;
    void dfs(const string &port){
        result.push_back(port);
        auto &pq=graph[port];
        while(!pq.empty()){
            string temp=pq.top();
            pq.pop();
            dfs(temp);
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ticks:tickets){
            graph[ticks[0]].push(ticks[1]);
        }
        dfs("JFK");
        return result;    
    }
};
int main (){
    Solution sol;
    vector<vector<string>> t1={{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    vector<string>t11=sol.findItinerary(t1);
    for (auto t:t11){
        cout << t << " ";
    }
    return 0;
}
