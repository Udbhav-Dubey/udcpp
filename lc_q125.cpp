#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int k;
        string ans;
        while(i<j){
                 while (i < j && !isalnum(s[i])) i++;
                while (i < j && !isalnum(s[j])) j--;
                if (tolower(s[i]) != tolower(s[j])) return false;
                i++;
                j--;
        }
        return true;
    }
};
int main (){
    string s;
    cout << "enter the string : ";
    cin >> s;
    Solution sol;
    cout << sol.isPalindrome(s);  
    return 0;
}
