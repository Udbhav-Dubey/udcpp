#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq={1,2,3,4,5};
    cout << "first element is " << *dq.cbegin() << endl;
    cout << "last element is " << *(--dq.cend()) << endl;
return 0;
}
