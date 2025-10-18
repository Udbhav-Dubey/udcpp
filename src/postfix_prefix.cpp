#include <bits/stdc++.h>
using namespace std;
int precedence(char op){
    if (op=='+'||op=='-') return 1;
    if (op=='*'||op=='/') return 2;
    if (op=='^')return 3;
    return 0;
}
bool isoperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}
string infixToPostfix(string exp){
    stack<char> st;
    string result;
    for (char c:exp){
        if (isalnum(c)){
            result +=c;
        }
        else if (c=='('){
            st.push(c);
        }
        else if (c==')'){
            while(!st.empty()&&st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if (!isoperator(c)){
            while(!st.empty()&&precedence(st.top())>=precedence(c)){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int main (){
return 0;
}
