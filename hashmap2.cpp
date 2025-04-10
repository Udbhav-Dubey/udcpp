#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,int> freq;
    freq[3]=312;
    freq[4]=41;
    freq[-3]=31;
    freq[-1]=44;
    freq[3]++;
    for(auto i : freq){
        cout << i.first << "->" << i.second << endl;
    }
    return 0;
}
