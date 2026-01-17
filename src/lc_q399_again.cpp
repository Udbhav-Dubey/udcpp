#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string,vector<pair<string,double>>>adj;
    for (int i=0;i<equations.size();i++){
        string u=equations[i][0];
        string v=equations[i][1];
        int wal=values[i];
        adj[u].push_back({v,wal});
        adj[v].push_back({u,1/wal});
    }
    vector<double>result;   
    for (auto &q:queries){
    string u=q[0];
    string v=q[1];
    if (!adj.count(u)||!adj.count(v)){
        result.push_back(-1.0);
    }
    else if (u==v){result.push_back(1.0);}
    else{
        set<string> visited;
        result.push_back(dfs(u,v,visited,adj));
    }
    }
    return result;
    }
    double dfs(string u,string v,set<string>&visited,unordered_map<string,vector<pair<string,double>>>&adj){
        visited.insert(u);
        for (auto &p:adj[u]){
            if (visited.count(p.first)){continue;}
            double val=dfs(p.first,v,visited,adj);
            if (val!=-1.0){return val*p.second;}
        }
        return -1.0;
    }
};

int main() {
    Solution sol;

    // ---------- Test Case 1 ----------
    vector<vector<string>> equations1 = {
        {"a", "b"},
        {"b", "c"}
    };
    vector<double> values1 = {2.0, 3.0};
    vector<vector<string>> queries1 = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"}
    };

    cout << "Test Case 1:\n";
    auto res1 = sol.calcEquation(equations1, values1, queries1);
    for (double x : res1) cout << x << " ";
    cout << "\nExpected: 6 0.5 -1 1 -1\n\n";


    // ---------- Test Case 2 ----------
    vector<vector<string>> equations2 = {
        {"x", "y"}
    };
    vector<double> values2 = {4.0};
    vector<vector<string>> queries2 = {
        {"x", "y"},
        {"y", "x"},
        {"x", "x"},
        {"y", "y"}
    };

    cout << "Test Case 2:\n";
    auto res2 = sol.calcEquation(equations2, values2, queries2);
    for (double x : res2) cout << x << " ";
    cout << "\nExpected: 4 0.25 1 1\n\n";


    // ---------- Test Case 3 ----------
    vector<vector<string>> equations3 = {
        {"a", "b"},
        {"c", "d"}
    };
    vector<double> values3 = {1.5, 2.5};
    vector<vector<string>> queries3 = {
        {"a", "b"},
        {"c", "d"},
        {"a", "d"},
        {"b", "c"}
    };

    cout << "Test Case 3:\n";
    auto res3 = sol.calcEquation(equations3, values3, queries3);
    for (double x : res3) cout << x << " ";
    cout << "\nExpected: 1.5 2.5 -1 -1\n";

    return 0;
}
