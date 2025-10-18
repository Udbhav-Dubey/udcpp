// program to find sum of digits of a number
#include <iostream>
using namespace std;
int main (){
	int numb,sum=0;
	cout << "please enter the number\n";
	cin >> numb;
	for (int i=0;numb!=0;i++){
	sum += numb%10;
	numb = numb/10;
	}
	cout << sum << endl;
return 0;
}
