#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for (char &c:s){
            if (c=='6'){
                c='9';
                break;
            }
        }
        return stoi(s);
    }
};
int main (){
    cout << "insert a number : ";
    int num;
    cin>>num;
    Solution sol;
    cout<<sol.maximum69Number(num);
return 0;
}
