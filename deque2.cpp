#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq;
    dq.push_back(5);
    dq.push_back(4);
    dq.push_back(3);
    dq.push_back(2);
    dq.push_back(1);
    for (auto it : dq){
        cout << it << " ";
    }
    deque <int> d;
    cout << "\n";
     d.push_front(5);
     d.push_front(4);
     d.push_front(3);
     d.push_front(2);
     d.push_front(1);
     for (auto ti : d){
        cout << ti << " ";
     }
return 0;
}
