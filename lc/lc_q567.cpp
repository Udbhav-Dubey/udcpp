#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
	if (s1.length() > s2.length()) return false;
        int ctr_s1[26]={0};
        int window[26]={0};
        for (int i =0 ;i<s1.length();i++){
            ctr_s1[s1[i]-'a']++;
        }
        for (int i=0;i<s1.size();i++){
            window[s2[i]-'a']++;
        }
        int ss1=s1.length();
        int left=0;
	if (memcmp(ctr_s1, window, sizeof ctr_s1) == 0) return true;
        for (int right=ss1;right<s2.length();right++){
            window[s2[left]-'a']--;
            window[s2[right]-'a']++;
            left++;
            if (memcmp(ctr_s1, window, sizeof ctr_s1) == 0) return true;
        }
        return false;
    }
};
int main (){
    cout << "enter the string 1 : ";
    string s1;
    cin >> s1;
    cout << "enter the string 2 :";
    string s2;
    cin >> s2;
    Solution sol;
    cout << "the output is " << sol.checkInclusion(s1,s2);
return 0;
}
