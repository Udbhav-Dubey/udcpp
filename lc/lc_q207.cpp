class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for (auto&i:prerequisites){
            int course=i[0];
            int prereq=i[1];
            adj[prereq].push_back(course);
        }
            vector<int>visited(numCourses,0);
            for (int i=0;i<numCourses;i++){
                if (visited[i]==0){
                    if (isCycle(i,adj,visited)){return false;}
                }
            }
        return true;      
    }
    bool isCycle(int i,vector<vector<int>>&adj,vector<int>&visited){
        if (visited[i]==1){return true;}
        if (visited[i]==2){return false;}
        visited[i]=1; // visiting
        for (int j:adj[i]){
            if (isCycle(j,adj,visited)){return true;}
        }
        visited[i]=2; // done
        return false;
    }
};
