#include <bits/stdc++.h>
using namespace std;
int main (){
    queue<int> q;
    q.emplace(1);
    q.emplace(2);
    q.emplace(3);
    q.emplace(4);
    q.emplace(5);
    q.emplace(6);
    while(q.empty()==0){
        cout << q.front() << " ";
        q.pop();
    }
return 0;
}
