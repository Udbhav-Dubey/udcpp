#include <iostream>
using namespace std;
int pow(int base , int power){
        if (power==0){
            return 1;
        }        
        else {return base * pow(base,power-1);}

}
int main (){
    cout << "please enter the numbers to find power\n";
    cout << "input base number";
    int base;
    cin >> base ;
    int power;
    cin >> power;
    printf("\n%d\n",pow(base,power));
return 0;
}
