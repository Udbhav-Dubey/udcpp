#include <bits/stdc++.h>
using namespace std;
class Solution {
public :
    string minRemoveToMakeValid(string s){
        stack <int> stk;
        unordered_set<int>remove;
        for (int i=0;i<s.size();i++){
            if (s[i]=='('){
                stk.push(i);
            }
            else if (s[i]==')'){
                if (!stk.empty()){
                    stk.pop();
                }
                else {
                    remove.insert(i);
                }
            }
        }
        while(!stk.empty()){
            remove.insert(stk.top());
            stk.pop();
        }
        string result;
        for (int i=0;i<s.size();i++){
            if (remove.find(i)==remove.end()){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
int main (){
    string s;
    cout << "input the string : " << endl;
    cin >>s;
    Solution sol;
    string answer=sol.minRemoveToMakeValid(s);
    cout << answer;
    return 0;
}
