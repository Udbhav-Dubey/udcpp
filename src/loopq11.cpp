// program to find first and last digit of a number.
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the number to find 1st and last digit\n";
	int numb,lastdig,firstdig;
	cin >> numb;
	lastdig= numb % 10;
	firstdig = numb;
	while (firstdig >= 10) {
        firstdig /= 10;
    }
	cout << "firstdig : " << firstdig << endl;
	cout << "lastdig : " << lastdig << endl;
return 0;
}
