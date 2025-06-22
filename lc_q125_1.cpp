#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) i++;
            while (i < j && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))) j--;
            char left = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
            char right = (s[j] >= 'A' && s[j] <= 'Z') ? s[j] + 32 : s[j];
            if (left != right) return false;
            i++;
            j--;
        }
        return true;
    }
};
int main() {
    string s;
    getline(cin, s);
    Solution sol;
    cout << (sol.isPalindrome(s) ? "true" : "false");
    return 0;
}

