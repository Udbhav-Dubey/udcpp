//Simple Calculator using the switch
#include <iostream>
using namespace std;
int main (){
	char c;
	cout << "enter numb1 and 2\n";
	int numb1 , numb2;
	cin >> numb1 >> numb2 ;
	cout << "enter the operation\n";
	cin >> c;
	switch (c){
		case '+': 
			cout << numb1 << "+" << numb2 << "=" << numb1+numb2 << endl;
			break;
		case '-': 
			cout << numb1 << "-" << numb2 << "=" << numb1-numb2 << endl;
			break;
		case 'X': 
			cout << numb1 << "X" << numb2 << "=" << numb1*numb2 << endl; 
			break;
		case '/': 
			cout << numb1 << "/" << numb2 << "=" << numb1/numb2 << endl;
			break;
	}
return 0;
}
