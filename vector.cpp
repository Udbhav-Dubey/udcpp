#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int>v1={1,3,5,7};
    vector<int>v2(5,9);
    for (int i=0;i<v1.size();i++){
        cout << v1[i] << " " ;
    }
    cout << endl;
    for (int i=0;i<v2.size();i++){
        cout << v2[i] << " "; 
    }
return 0;
}
