class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> adj(numCourses);
        for (auto &it:prerequisites){
            int first=it[0];
            int second=it[1];
            adj[second].push_back(first);
        }
        int flag=0;
        vector<int>visited(numCourses,0);
        for (int i=0;i<numCourses;i++){
            if (visited[i]==0){
                dfs(i,adj,result,visited,flag);
            }
        }
        if (flag==0){reverse(result.begin(),result.end());}
        else {return {};}
        return result;
    }
    void dfs(int i,vector<vector<int>>&adj,vector<int>&result,vector<int>&visited,int &flag){
        if (flag) return;
        if (visited[i]==1){ flag=1; return ;}
        if (visited[i]==2){return ;}
        visited[i]=1;
        for (int j:adj[i]){
            dfs(j,adj,result,visited,flag);
        }
        result.push_back(i);
        visited[i]=2;
    }
};
