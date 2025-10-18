#include <bits/stdc++.h>
using namespace std;
int main (){
    deque <int>d1={1,2,3};
    deque <int>d2={3,1,2,4};
    cout << "d1 is : " ;
    for (auto it : d1 ){
        cout << it << " ";
    }
    printf("\n");
    cout << "checking at [2] : " << d1[2] << endl; 
    d1=d2;
    cout << "checking at [2] : " << d1[2]<< endl;
    cout << "after d1=d2 : ";
    for (auto it : d1){
        cout << it << " ";
    }
return 0;
}
