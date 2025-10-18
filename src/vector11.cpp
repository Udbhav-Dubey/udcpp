#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int>v={1,3,5,6,7};
    v.erase(v.begin()+2);
    v.erase(v.end()-1);
    for (auto i:v){
        cout << i << " ";
    }
return 0;
}
