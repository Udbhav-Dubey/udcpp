#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int schedulecourse(vector<vector<int>>&courses){
            sort(courses.begin(),courses.end(),[](vector<int>&x,vector<int>&y){
            return x[0]<y[0];
                    });
            int count=0;
            priority_queue<int>pq;
            for (auto c : courses){
                count+=c[0];
                pq.push(c[0]);
                if (count>c[1]){
                    time-=pq.top();
                    pq.pop();
                }
            }
            return pq.size();
        }
};
int main (){
    return 0;
}
