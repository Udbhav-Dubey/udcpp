#include <iostream>
#include <queue>
using namespace std;
int main (){
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
