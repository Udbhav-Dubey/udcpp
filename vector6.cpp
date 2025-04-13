#include <iostream>
#include <vector>
using namespace std;
int main (){
    vector <string> v={"finally","the rock has come back"};
    v.push_back("to raw");
    for (string s:v){
        cout << s << " ";
    }

return 0;
}
