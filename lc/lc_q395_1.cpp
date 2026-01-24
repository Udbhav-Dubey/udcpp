class Solution{
    public:
        int longestSubstring(string s,int k){
            int n=s.size();
            unordered_map<char,int>mp;
            for (int i=0;i<n;i++){
                mp[s[i]]++;
            }
            int left=0;
            while(left<n&&mp[s[left]]>=k){
                left++;
            }
            if (left>=n){return left;}
            int l1=longestSubstring(s.substr(0,left),k);
            int l2=longestSubstring(s.substr(left+1),k);
            return max(l1,l2);
        }
}
