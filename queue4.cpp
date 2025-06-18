#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);

    cout << "printing in forward dirn : "  ;
    for (auto it = dq.cbegin();it!=dq.cend();it++){
        cout << *it << " ";
    }
    cout << "\nprinting in backward dirn : ";
    for (auto it=dq.crbegin();it!=dq.crend();it++){
        cout << *it << " ";
    }
return 0;
}
