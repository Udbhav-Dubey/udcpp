class Solution {
public:
    int countBinarySubstrings(string s) {
       int prev=0,curr=1;
       int ans=0;
       for (int i=1;i<=s.length();i++){
        if (s[i-1]==s[i]){
            curr++;
        }
        else {
            ans+=min(curr,prev);
            prev=curr;
            curr=1;
        }
       }
       return ans+=min(curr,prev);
    }
};
