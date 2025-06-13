#include <bits/stdc++.h>
using namespace std;
int main (){
    string str[]={"the","people's","champion"};
    int n=(sizeof(str)/sizeof(str[0]));
     unordered_set<string> s(str,str+n);
    for (auto it : s){
        cout << it << " ";
    }
return 0;
}
