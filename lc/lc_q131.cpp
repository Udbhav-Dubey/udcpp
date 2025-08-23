#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(const string &s,int l ,int r){
        while(l<r){
            if (s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void backtrack(string &s,vector<string> &muller,int index,vector<vector<string>> &result){
        if (index==s.size()){
            result.push_back(muller);
            return ;
        }
        for (int i=index;i<s.size();i++){
            if (check(s,index,i)){
            string c=s.substr(index,i-index+1);
            muller.push_back(c);
            backtrack(s,muller,i+1,result);
            muller.pop_back();
        }}
    }
    vector<vector<string>> partition(string s) {
        vector <vector<string>> result;
        vector <string> muller;
        backtrack(s,muller,0,result);
        return result;
    }
};
int main (){
    string s;
    cout << "please enter the string : ";
    cin >> s;
    Solution sol;
    vector <vector<string>> answer=sol.partition(s);
    for (auto it : answer){
            for (auto i:it){
                cout << i << " ";
            }
            cout << endl;
    }

return 0;
}
