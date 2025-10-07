#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector <string> splitPath(const string &path){
        vector <string> tokens;
        int n=path.size();
        for (int i=0;i<n;i++){
            while(i<n&&path[i]=='/')i++;
            if (i>=n) break;
            string temp;
            while(i<n&&path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }
            if (!temp.empty()){
                tokens.push_back(temp);
            }
        }
        return tokens;
    }
    string simplifyPath(string path){
        vector <string> tokens=splitPath(path);
        vector <string> st;
        for (auto &tok:tokens){
            if (tok=="."||tok.empty()){continue;}
            else if (tok==".."){
                if (!st.empty()) st.pop_back();
            }else {st.push_back(tok);}
        }
        string ans="/";
        for (int i=0;i<(int)st.size();i++){
            ans+=st[i];
            if (i+1<st.size())ans+="/";
                }
        return ans;
    }
};
int main (){
    string path;
    cin >> path;
    Solution sol;
    cout << sol.simplifyPath(sol.simplifyPath(path));
    return 0;
}
