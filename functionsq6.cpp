#include <iostream>
using namespace std;
int prime(int upp,int low){
    int i;
    for (i=low;i<=upp;i++){
         for (int k=2;k<i;k++){
            if (i%k==0){
            break;
            }
            else {printf(":")}
         }
    }
}
int main (){
    cout << "program to find prime numbers in given range using functions\n";
    cout << "enter the upper range : ";
    int upp;
    cin >> upp;
    cout << "enter the lower range : ";
    int low;
    cin >> low;
    prime (upp,low);
return 0;
}
