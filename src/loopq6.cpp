//  program to find sum of all natural numbers between 1 to n.
#include <iostream>
using namespace std;
int main (){
	int n,sum=0;
	cout << "please enter the number to get sum of all\n";
	cin >> n;
	for (int i=1;i<=n;i++){
	sum += i ;
	}
	cout << sum << endl;
return 0;
}
