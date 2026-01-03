#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>map;
        for (auto &word:wordList){
            if (word==beginWord){map[word]=1;}
            else map[word]=0;
        }
        if (map.find(endWord)==map.end()){
            return 0;
        }
        int count=1;
        queue<string>q;
        q.push(beginWord);
        int len=beginWord.size();
        while(!q.empty()){
            int nq=q.size();
            for (int u=0;u<nq;u++){
            string word=q.front();
            q.pop();
            if (word==endWord){return count;}
            for (int i=0;i<len;i++){
            string temp=word;
            char tmp=temp[i];
            for (int j=0;j<26;j++){
                if (temp[i]=='z'){tmp='a';}
                else {tmp++;}
                temp[i]=tmp;
                cout << "when word is " << word << " temp is "<< temp << "\n";
                if (map.count(temp)&&!map[temp]){
                        if (temp==endWord){return count+1;}
                        q.push(temp);
                        map[temp]=1;
                    }
                }
            }  
        }
            count++;
        }
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // -------- Local Test Case --------
//    string beginWord = "hit";
 //   string endWord = "cog";
   // vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
string beginWord = "a";
    string endWord = "c";
    vector<string> wordList = {"a", "b", "c"};


    Solution sol;
    int result = sol.ladderLength(beginWord, endWord, wordList);

    cout << "Result: " << result << "\n"; // Expected: 5

    return 0;
}

