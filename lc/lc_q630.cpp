#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size()==1){
            if (courses[0][0]<=courses[0][1]){
                return 1;
            }
            else return 0;
        }
        auto cmp=[](const vector<int>&x,const vector<int>&y){
            return x[1]>y[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)>q(cmp);
        for (auto &p:courses){
            q.push(p);
        }
        int count=0;
        int last=0;
        while(!q.empty()){
            vector<int>vec;
            vec=q.top();
            q.pop();
            last+=vec[0];
            if (vec[0]>vec[1]){continue;}

            count++;
            if (vec[1]<=last){
                if (vec[1]==vec[0]+last){count++;}
                else break;
            }
            
            cout << "vec[0]" << vec[0] << "\n";
            cout << "vec[1]" << vec[1] << "\n";
            cout << "last : "<<last << "\n";
            vec.clear();
        }
    return count;
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

