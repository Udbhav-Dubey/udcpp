// program to print all odd numbers between 1 to 100. 
#include <iostream>
using namespace std;
int main (){
	int x=1;
	do {
	if (x%2!=0){
	cout << x << endl;}
	x++;
	} while (x<=100);
return 0;
}
