#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector<int>v={1,4,5,6};
    try {
        cout << v.at(5) << endl;
    }
    catch (const out_of_range&e){
        cout << "exception : "<< e.what()<< endl;
    }
return 0;
}
