// program to find frequency of each digit in a given integer.
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the number to find frequency of each digit in a givin integer\n";
	int numb,dig;
	cin >> numb;
	int arr [10]={0};
	for (int i=0;numb!=0;i++){
	dig = numb % 10;
	arr [dig] ++;
	numb = numb /10;
	}
	for (int i=0;i<=9;i++){
	cout << i << ":" <<  arr [i] << endl;
	}
return 0;
}
