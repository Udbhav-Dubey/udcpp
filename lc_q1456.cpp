#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  static bool is_vowel(char c){
        if (c=='a'||c=='e'||c=='i'||c=='o'||c='u') {return true;}
        else return false;
    }
    int maxVowels(string s, int k) {
        int left=0,maxi=0,vow=0;
        for (int i=0;i<s.size();i++){
            if (is_vowel(s[i])==1){
                vow++;
            }
            if (right-left+1==k){
                maxi=max(maxi,vow);
                if(is_vowel(s[left])) vow--;
                left++;
            }
        }
        return maxi;
    }
};
int main (){
    cout << "please enter the string : ";
    string s;
    cin >> s;
    cout << "please enter the k :";
    int k;
    cin >> k;
    Solution sol;
    cout << "your answer is " << sol.maxVowels(s,k);
    return 0;
return 0;
}
