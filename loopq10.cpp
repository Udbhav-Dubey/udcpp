// program to count number of digits in a number.
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the number\n";
	int numb;
	cin >> numb;
	int i;
	for (i=0;numb!=0;i++){
	numb = numb /10 ;
	}
	cout << i << endl;
return 0;
}
