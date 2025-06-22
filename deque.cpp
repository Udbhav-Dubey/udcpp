#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq={1,2,3,4,5};
    for (auto x : dq){
        cout << x << " ";
    }
    cout << endl;
    deque<int> d(3,5);
    for (auto it:d){
        cout << it << " ";
    }
return 0;
}
