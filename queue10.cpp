#include <bits/stdc++.h>
using namespace std;
int main (){
    queue<char> q1,q2;
    int v=96;
    for (int i=0;i<5;i++){
        q1.push(v+1);
        v++;
    }
    int V=65;
    for (int i=0;i<4;i++){
        q2.push(V+1);
        V++;
    }
    q1.swap(q2);
    cout << "queue1 = ";
    while (!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << "\nqueue2 = ";
    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }
return 0;
}
