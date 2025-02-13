// program to calculate factorial of a number.
#include <iostream>
using namespace std;
int main (){
	int numb,result=1;;
	cout << "please enter the number to find the factorial\n";
	cin >> numb;
	for (int i=1;i<=numb;i++){
	result *= i ;
	}
	cout << result ;
return 0;
}
