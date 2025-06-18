#include <bits/stdc++.h>
using namespace std;
int main (){
    queue <int> q;
    q.push (32);
    q.push (11);
    q.push (32);
    q.push (44);
    cout << "the elements are : " ;
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
return 0;
}
