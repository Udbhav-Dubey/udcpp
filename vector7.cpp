#include <bits/stdc++.h>
using namespace std;
int main (){
    vector <char> v={'a','e','d'};
    v.push_back('z');
    v.insert(v.begin()+1,'c');
    for (char i:v){
        cout << i << " ";
    }
    return 0;

}
