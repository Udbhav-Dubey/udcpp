#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>deads;
        unordered_set<string>visited;
        for (auto &dead:deadends){
            if (dead=="0000"){return -1;}
            deads.insert(dead);
        }
        int spread=1;
        if (target=="0000"){
            return 0;
        }
        string init="0000";
        queue<string>q;
        q.push(init);
        visited.insert(init);
        while(!q.empty()){
            int len=q.size();
            while(len--){
                string str=q.front();
                q.pop();
                if (str==target){return spread;}
                for (int i=0;i<4;i++){
                    string s=str;
                    int d=s[i]-'0';
                    (d==9)?d=0:d++;
                    s[i]=d+'0';
                if (s==target){return spread;}
                    if (deads.count(s)==0&&visited.count(s)==0){q.push(s);visited.insert(s);}
                }
                for (int i=0;i<4;i++){
                    string s=str;
                    int d=s[i]-'0';
                    (d==0)?d=9:d--;
                    s[i]=d+'0';
                if (s==target){return spread;}
                    if (deads.count(s)==0&&visited.count(s)==0){q.push(s);visited.insert(s);}
                }
            }
            spread++;
        }
        return -1;

    }
};
int main (){
    Solution sol;
    vector<string> dead1 = {"0201","0101","0102","1212","2002"};
    string target1 = "0202";
    cout << sol.openLock(dead1, target1) << endl; // Expected: 6

    // Example 2
    vector<string> dead2 = {"8888"};
    string target2 = "0009";
    cout << sol.openLock(dead2, target2) << endl; // Expected: 1

    // Example 3
    vector<string> dead3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target3 = "8888";
    cout << sol.openLock(dead3, target3) << endl; // Expected: -1

    return 0;
}
