// program to find sum of all odd numbers between 1 to n.
#include <iostream>
using namespace std;
int main (){
	int n;
	long long int sum=0;
	cout << "please enter the number to find sum of all odd till the number\n";
	cin >> n;
	for (int i=1;i<=n;i++){
	if (i%2!=0){
	sum += i ;
	}
	}
	cout << sum;
return 0;
}
