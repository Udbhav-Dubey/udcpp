#include <iostream>
using namespace std;
void prime(int upp,int low){
    int i,flag=0;
    for (i=low;i<=upp;i++){
        	flag=0;
         for (int k=2;k<i;k++){
            if (i%k==0){
            flag=1;
            }
         }
        if (flag==0){
         printf("%d ",i);}
         
    }
return;
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
