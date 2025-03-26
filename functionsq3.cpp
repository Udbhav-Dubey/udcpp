#include <iostream>
using namespace std;
int max (int a , int b){
    return (a>b)? a : b;
}
int min (int a,int b){
    return (a<b)? a:b;
}
int main (){
        cout << " to find maximum and minimum using functions\n";
        int a,b;
        cin >> a >> b ;
        cout << "the maximum is " << max(a,b) << "\nthe minimum is " << min (a,b) << endl;
return 0;
}
