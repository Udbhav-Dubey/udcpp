#include <iostream>
#include <unordered_set>
using namespace std;
int main (){
    unordered_Set <int> emptyus;
    unordered_set<int> us={1,2,3,4,5,4};
    for (auto i: us){
        cout << i << " ";
    }
}
