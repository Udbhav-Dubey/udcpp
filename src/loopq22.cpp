// program to find all factors of a number
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the number to find all factors\n";
	int numb;
	cin >> numb;
	for (int i=1;i<=numb;i++){
	if (numb % i == 0 ) {
		cout << i << " " ;
	}
	}
return 0;
}
