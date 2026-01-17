#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>projects;
        for (int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }
        sort (projects.begin(),projects.end());
        priority_queue<int>pq;
        int i=0;
        while(k>0){
            while(i<n&&w>=projects[i].first){
                pq.push(projects[i].second);
                i++;
            }
            if (pq.empty()) {break;}
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
int main (){
    Solution sol;
    int k=2;
    int w=0;
    vector<int>profits={1,2,3};
    vector<int>capital={0,1,1};
    cout << "ans= " << sol.findMaximizedCapital(k,w,profits,capital);
    return 0;
}
