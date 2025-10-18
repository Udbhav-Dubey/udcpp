#include <iostream>
#include <queue>
using namespace std;
int main (){
    queue <int> q;
    q.push(8);
    q.push(7);
    q.push(6);
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    if (q.front()>q.back()){
        cout << q.front()-q.back() << endl;
    }
    else if (q.front()<q.back()){
        cout << q.back()-q.front() << endl;    
    }
    else cout << "0";
    return 0;
}

