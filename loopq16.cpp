//program to enter a number and print its reverse.
#include <iostream>
#include <cmath>
using namespace std;
int main (){
	cout << "program to enter a number and print its reverse\n";
	int numb,reverse=0;
	cin >> numb;
	for (int i=0;numb!=0;i++){
		reverse = (reverse*10) + (numb%10);
		numb = numb /10;
	}
	cout << reverse ;
return 0;
}
