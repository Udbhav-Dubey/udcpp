//program to check Leap Year
#include <iostream>
using namespace std;
int main (){
	cout << "please enter your year\n";
	int year;
	cin >> year;
	if ((year%4==0) && (year%100!=0) || (year%400==0)){
		cout << "leap year\n";
	}
	else {cout << "not a leap year\n";}
	return 0;
}
