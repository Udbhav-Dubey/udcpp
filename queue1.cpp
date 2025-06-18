#include <bits/stdc++.h>
using namespace std;
int main (){
    queue <int> q;
    q.push(3);
    q.push(44);
    q.push(555);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.back() ; 
return 0;
}
