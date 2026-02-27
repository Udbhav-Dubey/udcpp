#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        for (int i=0;i<n;i++){
            count+=expand(s,i,i,n);
            count+=expand(s,i,i+1,n);
        }
        return count;
    }
    int expand(string &s,int left,int right,int n){
        int count=0;
        while(left>=0&&right<n&&s[left]==s[right]){
            count++;
            left--;
            right++;
        }
        return count;
    }
};
int main (){
    vector<string>vec={"abc","aaa","aba"};
    Solution sol;
    for (auto s:vec){
        cout << s << "  " << sol.countSubstrings(s) << "\n";
    }
    return 0;
}
