#include <bits/stdc++.h>
using namespace std;
long long pow(long long b,long long e){
    if (e==0){
        return 1; 
    }
    if (e<=0){
        return 1/pow(b,-e);
    }
    long long temp=pow(b,e/2);
    if (e%2==0){return temp*temp;}
    else {return b*temp*temp;}
}
int main (){
    long long base,expo;
    cout << "enter base \n";
    cin>>base;
    cout << "enter expo \n";
    cin>>expo;
    cout <<  pow(base,expo) << "\n";
    return 0;
}
