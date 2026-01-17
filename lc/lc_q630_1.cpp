#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(),courses.end(),[](const vector<int>&a,const vector<int>&b){
            if (a[1]!=b[1]){return a[1]<b[1];}
            else return a[0]<b[0];
            });
    priority_queue<int>pq;
    int count=0;
    int time=0;
    for (auto c:courses){
        if (c[0]>c[1]){continue;}
        time+=c[0];
        pq.push(c[0]);
        cout << " time "  << time << " c[1] " << c[1] << "\n";
        if (time>c[1]){
            time-=pq.top();
            pq.pop();
        }
        else {count++;}
    }
    return pq.size();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;

    vector<vector<int>> courses = {
        {100, 200},
        {200, 1300},
        {1000, 1250},
        {2000, 3200}
    };

    int ans = sol.scheduleCourse(courses);
    cout << ans << "\n";
    cout << "test 2 \n";
    vector<vector<int>>coursess={{5,5},{4,6},{2,6}};
    ans=sol.scheduleCourse(coursess);
    cout << ans<<"\n";
    return 0;
}

