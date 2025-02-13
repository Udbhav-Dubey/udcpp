// program to find power of a number using for loop
#include <iostream>
using namespace std;
int main (){
	cout << "intput base : ";
	int base,result=1;
	cin >> base;
	cout << "input exponent : ";
	int exponent;
	cin >> exponent;
	for (int i=1;i<=exponent;i++){
	result = result * base ;
	}
	cout << "result is : " << result;
return 0;
}
