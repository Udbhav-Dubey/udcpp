#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq={1,2,3,4,5,6,7,8};
    auto it = dq.begin();
    ++it;
    it=dq.insert(it,10);
    for (auto i : dq){
        cout << i << " ";
    }
    auto i=dq.begin()+4;
    i=dq.insert(i,3,0);
    cout << endl;
    for (auto i : dq){
        cout << i << " ";
    }
    i=i+3;
    i=dq.insert(i,3,10);
    cout << endl;
    for (auto i : dq){
        cout << i << " ";
    }
return 0;
}
