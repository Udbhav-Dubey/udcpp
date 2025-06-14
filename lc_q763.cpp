#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastindex;
        for (int i=0;i<s.size();i++){
            lastindex[s[i]]=i;
        }
        vector<int>result;
        int start=0,end=0;
        for (int i=0;i<s.size();i++){
        if (lastindex[s[i]]>end){
            end=lastindex[s[i]];
        }
        if (i==end){
            result.push_back(end-start+1);
            start=i+1;
        }
    }
    return result;
};
