//C program to find all roots of a quadratic equation
#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int a,b,c;
	cout << "for ax^2  + bx + c enter a , b , c " << endl << "a : " ;
	cin >> a;
	cout << " b : ";
	cin >> b;
	cout << " c : ";
	cin >> c;
	int D = (b*b) - (4*a*c);
	if (D>0){
	float r1 = (-b+sqrt(D))/(2*a); 
	float r2 = (-b-sqrt(D))/(2*a);
	cout << "r1 : " << r1 << endl << "r2 : " << r2 << endl;
	}
	if (D==0){
	float r = -b/(2*a);
	cout << "roots are equal and equal to " << r << endl;
	}
	if (D<0){
	float r=-b/(2*a);
	float disc = sqrt(-D)/(2*a);
	cout << "r1 : " << "-"<< r << "+" << disc << endl << "r2 : " << r << "+" << disc << endl; 
	}
return 0;
}
