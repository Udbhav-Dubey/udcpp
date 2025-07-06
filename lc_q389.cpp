#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sums=0;
        int sumt=0;
        for (auto it : s){
            sums+=(it-'a');
        }
        for (auto it : t){
            sumt+=(it-'a');
        }
       int result=sumt-sums;
        return result+'a';
    }
};
int main (){
cout << "enter the string s : ";
string s,t;
cin >> s;
cout << "enter the string t : ";
cin>>t;
Solution sol;
cout << sol.findTheDifference(s,t);
return 0;
}
