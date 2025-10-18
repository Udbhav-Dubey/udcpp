// program to find sum of all even numbers between 1 to n.
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the number n to get sum of even numbers" << endl;
	int n;
	long long int sum=0;
	cin >> n;
	for (int i=1;i<=n;i++){
	if (i%2==0){
	sum += i ;
	}
	}
	cout << sum<< endl;
return 0;
}
