#include <bits/stdc++.h>
using namespace std;
int main (){
    queue<char> q;
    q.emplace('k');
    q.emplace('j');
    q.emplace('y');
    while(!q.empty()){
        cout <<" " << q.front();
        q.pop();
    }
return 0;
}
