// program to swap first and last digits of a number
#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int numb,ldig,fdig,nnumb;
	cout << "please enter the number to swap first and last digit of a number\n";
	cin >> numb;
	ldig = numb % 10;
	fdig = numb;
	int i;
	for (i=0;fdig>=10;i++){
	fdig= fdig/10;
	}
	 nnumb = ldig;
	 nnumb *= ( int )pow (10,i);
	 nnumb += numb % (int) pow(10,i);
	 nnumb -= ldig;
	 nnumb += fdig;
	 cout << nnumb <<endl;
return 0;
}
