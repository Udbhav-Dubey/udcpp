#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector <int>v={1,4,5};
    v.push_back(9);
    for (int i:v){
        cout << i << " ";
    }
return 0;
}
