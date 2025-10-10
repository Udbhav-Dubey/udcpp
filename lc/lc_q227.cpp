#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int calculate(string s){
        char seen='+';
        stack <int> st;
        int i=0;
        while(i<s.size()){
            while(i<s.size()&&s[i]==' '){i++;}
            int num=0;
            while(i<s.size()&&isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            if (seen=='+'){
                st.push(num);
            }
            else if (seen=='-'){
                num=-num;
                st.push(num);
            }
            else if (seen=='*'){
                int temp=st.top();
                st.pop();
                int result=temp*num;
                st.push(result);
            }
            else if (seen=='/'){
                int temp=st.top();
                st.pop();
                int result=temp/num;
                st.push(result);
            }

            while (i < n && s[i] == ' ') i++;
            if (i<s.size()) seen=s[i++];
        }
        int result=0;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            result+=temp;
        }
        return result;
    }
};
int main (){
    string s;
    cout << "please enter the string s : ";
    cin>>s;
    Solution sol;
    cout << sol.calculate(s);
    return 0;
}

