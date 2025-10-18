#include <iostream>
#define pie 3.14 
using namespace std;
double dia(double *r){
    double dia = 2 * *r ;
    return dia;
}
double area(double *r){
    double are = pie * *r * *r ;
    return are ;
}
int main (){
    cout << "please enter the value of radius\n";
    double r;
    cin >> r ;
    cout << "the diameter is " << dia(&r) << endl;
    cout << "the circumference is " << pie * dia(&r) << endl;
    cout << "the area is " << area(&r) << endl;
    return 0;
}
