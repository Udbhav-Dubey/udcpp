#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector <int>v={1,3,5,6};
    v.insert(v.begin()+1,3,2);
    for (auto i:v){
        cout << i << " ";
    }    
return 0;
}
