#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size()<2){
            if (arr.size()==1){return 0;}
            else return 1;
        }
        int n=arr.size();
        unordered_map<int,vector<int>>map;
        for (int i=0;i<n;i++){
            map[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<bool> visited(n,false);
        visited[0]=1;
        int count=0;
        while(!q.empty()){
            int nq=q.size();
            while(nq--){
            int temp=q.front();
            q.pop();
            if (temp==n-1){return count;}
            if (temp+1<n&&!visited[temp+1]){
                q.push(temp+1);
                visited[temp+1]=1;
            }
             if (temp-1>=0&&!visited[temp-1]){
                q.push(temp-1);
                visited[temp-1]=1;
            }
            auto &vec=map[arr[temp]];
            for (auto v:vec){
                if (!visited[v]){
                    q.push(v);
                    visited[v]=1;
                }
            }
            vec.clear();
            }
            count++;

        }
        return -1;
    }
};
int main() {
    Solution sol;

    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};

    int ans = sol.minJumps(arr);
    cout << ans << "\n";

    return 0;
}
