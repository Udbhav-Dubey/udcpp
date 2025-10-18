#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int>v={3,6,7};
    while(!v.empty())
        v.pop_back();

    cout << v.size();
return 0;
}
