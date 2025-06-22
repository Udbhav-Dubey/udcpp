#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int> dq={1,4,5};
    dq.push_back(6);
    dq.push_front(0);
    auto it = dq.begin()+2;
    dq.insert(it,11);
    auto it2=dq.end()-3;
    dq.insert(it2,17);
    for (auto i : dq ){
        cout << i << " ";
    }
    cout << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    for (int i =0;i<dq.size();i++){
        cout << dq[i] << " ";
    }
    cout << endl;
    dq[2]=2;
    dq.front()=2;
    for (auto i : dq){
        cout << i << " ";
    }
    cout << endl;
    dq.pop_back();
    dq.pop_front();
    dq.erase(dq.begin());
    for(int i=0;i<dq.size();i++){
        cout << dq[i] << " ";
    }
return 0;
}
