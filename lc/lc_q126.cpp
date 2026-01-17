#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        unordered_set<string> wset(wordList.begin(),wordList.end());
        if (wset.find(endWord)==wset.end())return {};
        unordered_map<string,int>visitedLevel;
        visitedLevel[beginWord]=0;
        bool found=0;
        int count=1;
        size_t wordlen=beginWord.size();
        queue<string>q;
        q.push(beginWord);
        unordered_map<string,vector<string>>adj;
        while(!q.empty()){
            int len=q.size();
            for (int i=0;i<len;i++){
            string s=q.front();
            q.pop();
            if (s==endWord){
                found=true;
                continue;
            }
            for (int j=0;j<wordlen;j++){
                    string temp=s;
                    char tempc=s[j];
                for (int k=0;k<26;k++){
                    if (tempc=='z'){tempc='a';}
                    else tempc++;
                    temp[j]=tempc;
                    if (wset.count(temp)){
                        if (visitedLevel.find(temp)==visitedLevel.end()||visitedLevel[temp]==count+1){
                            if (visitedLevel.find(temp)==visitedLevel.end()){
                                visitedLevel[temp]=count+1;
                                q.push(temp);
                            }
                        adj[temp].push_back(s);
                        }
                        //map[temp]=1;
                    }
                }
            }
            }
            if (found)break;
            count++;
        }
        if (found==0){
            return {};
        }
        vector<string>vec={endWord};
        dfs(endWord,beginWord,vec,adj,result);
        return result;
    }
    void dfs(string start,string end,vector<string>&vec,unordered_map<string,vector<string>>&adj,vector<vector<string>>&result){
        if (start==end){
            reverse(vec.begin(),vec.end());
            result.push_back(vec);
            reverse(vec.begin(),vec.end());
            return ;
        }
        for(auto u:adj[start]){
            vec.push_back(u);
            dfs(u,end,vec,adj,result);
            vec.pop_back();
        }
    }
};
int main() {
    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    for (auto &path : result) {
        for (auto &word : path) {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}

