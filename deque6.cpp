#include <bits/stdc++.h>
using namespace std;
int main (){
    deque<int> dq;
    dq.assign(5,10);
    for (auto it : dq){
        cout << it << " ";
    }
    cout << endl;
    dq.assign(10,5);
    for (auto it : dq){
        cout << it << " ";
    }
    cout << endl;
    vector <int> vec={1,2,3,4,5,6};
    auto it = vec.begin();
    it+=2;
    auto it2= vec.end();
    it2-=1;
    dq.assign(it,it2);
        for (auto it : dq){
            cout << it << " ";
        }
    cout << "\nmax size of dq is " << dq.max_size();
return 0;
}
