// program to find multiplication of digits of a number
#include <iostream>
using namespace std;
int main (){
	int numb,product=1;
	cout << "please enter the number\n";
	cin >> numb;
	for (int i=0;numb!=0;i++){
	product *= numb%10;
	numb = numb/10;
	}
	cout << product << endl;
return 0;
}
