#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int>v;
    cout << v.capacity()<< endl;
    v.reserve(9);
    cout << v.capacity()<< endl;
    v.reserve(7);
    cout << v.capacity()<<endl;
return 0;
}
