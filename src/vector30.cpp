#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int>v={1,2,4};
    v.resize(9,3);
    for (auto i:v){
        cout << i << " " ;
    }
return 0;
}
