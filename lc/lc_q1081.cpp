#include <bits/stdc++.h>
class Solution {
    public :
        string smallestSubsequence(string s){
            int freq[26]={0};
            bool seen[26]={0};
            stack <int> stk;
            for (int i=0;i<s.size();i++){
                freq[s[i]-'a']++;
            }
            for (auto c : s){
                freq[c-'a']--;
                if (seen[c-'a']==1){
                    continue;
                }
                while(!stk.empty()&&c<stk.top()&&freq[stk.top()-'a']>0){
                    seen[stk.top()-'a']=0;
                    stk.pop();
                }
                stk.push(c);
                seen[c-'a']=1;
            }
            string ans;
            while(!stk.empty()){
                ans+=stk.top();
                stk.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }

};
