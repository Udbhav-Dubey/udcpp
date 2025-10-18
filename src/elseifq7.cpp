// program to check whether a character is alphabet or not
#include <iostream>
using namespace std;
int main (){
	cout << "enter the alphabet\n";
	char ch;
	cin >> ch;
	if (((ch>='a') && (ch <='z')) || (ch >= 'A') && (ch <='Z') ){
		cout << "alphabet\n";
	}
	else {cout << "not a alphabet\n";}
	return 0;
}
