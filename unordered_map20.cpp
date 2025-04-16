#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,int>sample;
    sample={{1,2},{2,3},{4,5}};
    cout << sample.size()  << endl;
    cout << sample.bucket_count() << endl;
    sample.rehash(30);
    cout << sample.size() << endl;
    cout << sample.bucket_count() << endl;
return 0; 
}
