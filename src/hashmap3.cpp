#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_map<int,string> names;
    names[10]="udboi";
    names[-10]="kushi";
    names[69]="udbhav";
    names[-69]="udpie";
    names[0]="ud";
    for (auto x:names){
        cout << x.first << " -> " << x.second << endl;
    }
return 0;
}
