#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
            queue<int> R,D;
            for (int i=0;i<senate.size();i++){
                if (senate[i]=='R'){
                    R.push(i);
                }
                else {D.push(i);}
            }
            int n=senate.size();
            while(!R.empty()&&!D.empty()){
                if (R.front()<D.front()){
                   D.pop();
                   int temp=R.front()+n;
                   R.pop();
                   R.push(temp);
                }
                else {
                    R.pop();
                    int temp=D.front()+n;
                    D.pop();
                    D.push(temp);
                }
            }
            if (R.empty()){return "Dire";}
            else return "Radiant";
    }
};
int main (){
    return 0;
}
