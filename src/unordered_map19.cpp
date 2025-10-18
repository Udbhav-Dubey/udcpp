#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,int>sample;
    sample={{1,2},{2,3},{3,4}};
    cout << sample.max_size()<< endl;
return 0;
}
