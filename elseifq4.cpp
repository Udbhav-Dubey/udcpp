//  program to check whether a number is divisible by 5 and 11 or not
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the number\n";
	int x;
	cin >> x ;
	if ((x%5==0)&&(x%11==0)){
	cout << "divisible by 5 and 11 \n";
	}
	else {cout << "not divisible by 5 and 11\n";}

return 0;
}
