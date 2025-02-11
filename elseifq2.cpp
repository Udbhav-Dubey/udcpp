#include <iostream>
using namespace std;
int main (){
	int x,y,z;
	cout << "please enter the value of number 1 , 2 and 3 respectfully\n" ;
	cin >> x >> y >> z ;
	if (x>y){
	if (x>z){cout << x << " is maximum\n";}
	if (x==z) {cout << x << " and " << y << "are equal and maximux\n";}
	}
	if (x<y) {
	if (y>z){cout << y << " is maximum\n";}
	if (y==z) {cout << y << " and" << z << "are equal and maximux\n";}
	}
	if (x==y){
	if (x>z) {cout << x << " and" << y << "are equal and maximum\n";}
	if (x==z) {cout << "all are equal\n";}
	}
	if (z>y && z>x) {
		cout << z << " is maximux\n"; 
	}
return 0;
} 
