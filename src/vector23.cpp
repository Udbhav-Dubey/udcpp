#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector <int> v({5,24,53,25,412});
    v.assign({1,2,4});
    for (auto i:v)
        cout << i << " ";
return 0;
}
