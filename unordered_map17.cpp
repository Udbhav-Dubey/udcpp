#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,int> freq;
    freq={{2,3},
        {4,4},
        {5,1}
    };
    cout << freq.size() << endl;
return 0;
}
