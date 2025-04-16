#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
unordered_map<int,int>freq;
freq={{2,3},{1,4},{5,1}};
if (freq.empty()==1){
    cout << "yeah";
}
else {cout << "nah\n";}
freq.clear();
if (freq.empty()== 1){
    cout << "yeah";
}
else {cout << "nah";}
return 0;
}
