#include <bits/stdc++.h>
using namespace std;
int main (){
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    while (!q.empty()){
            cout << "size is  " << q.size() << endl;
            cout << q.front() << " ";
            q.pop();
    }
    cout << endl << q.empty() ;
return 0;
}
