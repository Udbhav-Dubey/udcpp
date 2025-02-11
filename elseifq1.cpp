#include <iostream>
using namespace std;
int main (){
	int x,y;
	cout << "please enter value of number 1 and 2 respectfully\n";
	cin >> x >> y ;
	if (x>y){
		cout << x << "is greater than " << y << endl;
	}
	else if (x==y){
		cout << x << "is equal to " << y << endl;
	}
	else {cout << y << " is greater than " << x  << endl;}
return 0;
}
