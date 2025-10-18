#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector <int> v={1,3,5,6};
    v.insert(v.begin()+2,8);
    for (int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
return 0;
}
