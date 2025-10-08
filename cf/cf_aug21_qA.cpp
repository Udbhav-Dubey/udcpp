#include <bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin>>t;
    while(t--){
        int na;
        cin>>na;
        string a;
        cin>>a;
        int nb;
        cin>>nb;
        string b;
        cin>>b;
        string c;
        cin>>c;
        int i=0;
        string frontPart, backPart = a;
        for (char ch : c) {
            if (ch == 'D') {
                backPart.push_back(b[i++]);   
            } else {
                frontPart.push_back(b[i++]);  
            }
        }
        reverse(frontPart.begin(), frontPart.end());
        cout << frontPart + backPart << endl;
    }
return 0;
}
