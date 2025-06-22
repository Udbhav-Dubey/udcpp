#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq={1,2,3,4,5};
    for (auto it : dq){
        cout << dq.size() << endl;
        for (auto it2 : dq){cout << it2 << " " ;}
        cout << endl;
        dq.pop_back();
        cout << "is dq empty :" << dq.empty() << endl;
    }
return 0;
}
