//program to check whether a number is Prime number or not.
#include <iostream>
using namespace std;
int main (){
	int numb,flag=0;
	cout << "please enter number to check for prime number\n";
	cin >> numb;
	if (numb<=1){
	cout << "not a prime number\n";
	}
	for (int i=2;i<numb;i++){
		if (numb%i==0){flag=1;break;}
	}
	if (flag ==1 ) {
	cout << "not a prime number\n"; }
	if (flag ==0 ) {
	cout << "prime number\n";
	}
return 0;
}
