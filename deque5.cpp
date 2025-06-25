#include <bits/stdc++.h>
using namespace std;
int main (){
    deque<int> d={1,2,3,4,5,7,8,9};
    deque<int>::iterator it;
    it=d.begin();
    d.erase(it);
    for (auto i : d){
        cout << i << " ";
    }
    printf("\n");
    auto it2=d.end();
    it2=it2-3;
    it=it+3;
    d.erase(it,it2);
    for (auto i : d){
        cout << i << " ";
    }
    d.clear();
    for (auto i : d){
        printf("clear");
        cout << i << " ";
    }
return 0;
}
