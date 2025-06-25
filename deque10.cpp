#include <bits/stdc++.h>
using namespace std;
void printer(deque<int>dq){
    for (auto it : dq){
        cout << it << " " ;
    }
    cout << endl;
}
int main (){
    deque <int> dq;
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    cout << dq.at(2)<< endl;
    cout << dq[2] << endl;
    cout << "original deque :" ;
    printer(dq);
    deque<int> dq2={1,2,3};
    cout << "2nd deque : ";
    printer(dq2);
    cout << "after swapping";
    dq.swap(dq2);
    cout << "original deque : ";
    printer(dq);
    cout << "2nd deque : ";
    printer(dq2);
return 0;
}
