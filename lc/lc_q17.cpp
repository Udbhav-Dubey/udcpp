#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(string &digits,unordered_map<char,string> &map,string &muller,int index,vector<string>&result){
        if(muller.size()==digits.size()){
            result.push_back(muller);
            return ;
        }
        for (char c:map[digits[index]]){
            muller.push_back(c);
            backtrack(digits,map,muller,index+1,result);
            muller.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
     if (digits.empty()) return {}; // edge case
        unordered_map<char,string> map={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector <string> result;
        string muller;
        backtrack(digits,map,muller,0,result);
        return result;
    }
};

    string digits;
    cout << "please enter the digits";
    cin >> digits;
    Solution sol;
    vector<string> answer=sol.letterCombinations(digits);
    for (auto it : answer){
        cout << it << " ";
    }
return 0;
}
