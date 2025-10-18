#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq={10,20,30,40,50};
    cout << "deque in reverse order : ";
    for (auto it = dq.rbegin();it!=dq.rend();++it){
        cout << *it << " ";
    }
return 0;
}
