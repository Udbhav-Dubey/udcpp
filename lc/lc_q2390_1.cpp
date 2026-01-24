class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        int count=0;
        string ans;
        for (int i=n-1;i>=0;i--){
            while(s[i]=='*'){
                i--;
                count++;
            }
            if (count!=0){
                i-=count;
                count=0;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};
