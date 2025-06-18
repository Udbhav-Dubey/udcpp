#include <bits/stdc++.h>
using namespace std;
int main (){
    queue <int>q;
    q.push(1);
    q.push(22);
    q.push(333);
    queue <int> temp(q);
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
        }
return 0;
}
