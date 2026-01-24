#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> helper(string expr){
        vector<int>ans;
        bool opflag=0;
        for (char c:expr){
            if(c=='+'||c=='*'||c=='-'){
                opflag=1;
                break;
            }
        }
        if (opflag!=1){
            ans.push_back(stoi(expr));
            return ans;
        }
        for (int i=0;i<expr.size();i++){
            char ch=expr[i];
            if (ch=='+'||ch=='-'||ch=='*'){
                string left=expr.substr(0,i);
                string right=expr.substr(i+1);
                vector<int>lef=helper(left);
                vector<int>righ=helper(right);
                for (int a:lef){
                    for (int b:righ){
                        if (ch=='+'){
                        ans.push_back(a+b);
                        }
                        else if (ch=='-'){
                        ans.push_back(a-b);
                        }
                        else if (ch=='*'){
                        ans.push_back(a*b);
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};
int main (){
    Solution sol;
    string s1="2-1-1";
    string s2="2*3-4*5";
    cout << "test 1 : \n";
    vector<int>t1=sol.diffWaysToCompute(s1);
    vector<int>t2=sol.diffWaysToCompute(s2);
    for (int i : t1){
        cout << i << "  ";
    }
    cout << "\n";
    cout << "test 2 : \n";
    for (int i:t2){
        cout << i << "  ";
    }
    cout << "\n";
    return 0;
}
