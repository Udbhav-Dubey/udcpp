#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        int minus;
        for (int i=0;i<s.size()-1;i++){
            if (s[i]>=s[i+1]){
                 minus = s[i]-s[i+1]; 
                 sum+=minus;
            }
            else {int minus=s[i+1]-s[i];
            sum+=minus;}
        }
        return sum;
    }
};
int main (){
    cout << "enter the string ";
    string s;
    getline(cin,s);
    Solution sol;
    cout << "the answer is " << sol.scoreOfString(s);
}
