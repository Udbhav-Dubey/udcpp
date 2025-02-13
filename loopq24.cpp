#include <iostream>
using namespace std;
int main (){
	int numb1,numb2,gcd=1;
	cout << "please enter the numbers" << "\nnumber 1 : ";
	cin >> numb1;
	cout << "number 2 : ";
	cin >> numb2;
	for (int i=1;i<= min(numb1,numb2);i++ ){
		if ((numb1%i==0) && (numb2%i==0)){
			gcd = i;
		}
			}
	cout << gcd<<endl;
	return 0;
}
