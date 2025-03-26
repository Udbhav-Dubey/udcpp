#include <iostream>
using namespace std;
double cube(double *a){
    double c= *a * *a * *a;
    return c;
    }
int main (){
        cout << "please enter the number : " ;
        double a ;
        cin >> a ;
        cout << "cube of a is " ;
        cout << cube(&a) << endl;
    
return 0;
 }
