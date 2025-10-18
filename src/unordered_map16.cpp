#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<string,int>marks;
    marks={{"rohit",64},{"aman",37},{"ayush bhai",96}};
    for (auto it=marks.begin();it!=marks.end();++it){
        cout << it->first << ":" << it->second << endl;
    }
    
return 0;
}
