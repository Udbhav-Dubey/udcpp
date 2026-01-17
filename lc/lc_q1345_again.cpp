#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int minJumps(vector<int>&arr){
             if(arr.size()<2){
            if (arr.size()==1){return 0;}
            else return 1;
            } 
            unordered_map<int,vector<int>>map;
            int n=arr.size();
            for (int i=0;i<n;i++){
                map[arr[i]].push_back(i);
            }
            int count=0;
            queue<int>q;
            q.push(0);
            vector<bool>visited(n,false);
            visited[0]=1;
            while(!q.empty()){
                int nq=q.size();
                while(nq--){
                int i=q.front();
                q.pop();
                if (i==n-1){return count;}
                if (i+1<n&&!visited[i+1]){
                    visited[i+1]=1;
                    q.push(i+1);
                }
                if (i-1>=0&&!visited[i-1]){
                    visited[i-1]=1;
                    q.push(i-1);
                }
                auto &vec=map[arr[i]];
                for (auto &v:vec){
                    if (!visited[v]){
                        visited[v]=1;
                        q.push(v);
                    }
                }
                vec.clear();
                }
                count++;
            }
            return -1;
        }
};
int main (){
    Solution sol;
    std::cout << "Test 1 \n";
    vector<int>arr={11,22,7,7,7,7,7,7,7,22,13};
    cout << " expected answer : 4 " << "your answer : " << sol.minJumps(arr); 
    return 0;
}
