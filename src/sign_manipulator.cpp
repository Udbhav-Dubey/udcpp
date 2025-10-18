#include <iostream>
#include <iomanip>
using namespace std;
int main (){
	int n =312;
	cout << left << setw(12)<< n << endl;	
	cout << right << setw(12)<< n << endl;
	cout << showpos << n << endl;
	cout << noshowpos << n;

return 0;
}
