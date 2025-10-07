#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector <int> ans;
        stack <int> stk;
            for (int i=0;i<asteroids.size();i++){
                bool flag=0;
                while(!stk.empty()&&stk.top()>0&&asteroids[i]<0){
                    if (abs(asteroids[i])>abs(stk.top())){
                        stk.pop();
                        continue;
                    }
                    if (abs(asteroids[i])==abs(stk.top())){
                        stk.pop();
                        flag=1;
                        break;
                    }
                    else{
                        flag=1;
                        break;}
                }
                if (!flag){
                stk.push(asteroids[i]);}
            }
            stack <int>st;
            while(!stk.empty()){
                st.push(stk.top());
                stk.pop();
            }
            while(!st.empty()){
               ans.push_back(st.top());
               st.pop();
            }
            return ans;
}
};
int main (){
    vector <int> asteroids={10,2,-5};
    Solution sol;
    vector <int> answer = sol.asteroidCollision(asteroids);
    for (auto num:answer){
        cout << num << " ";
    }
return 0;
}
