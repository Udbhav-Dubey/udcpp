#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>map;
        for (int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        vector <vector<char>> buckets(s.size()+1);
        for (auto &[ch,f] : map){
            buckets[f].push_back(ch);
        }
    string answer="";
        for (int i=s.size();i>=1;i--){
            for (char c:buckets[i]){
                answer+=string(i,c);
            }
        }
        return answer;
    }
};
int main (){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.frequencySort(s);
return 0;
}
