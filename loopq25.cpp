#include <iostream>
using namespace std;
int main (){
	int numb1,numb2,lcm=1;
	cout << "please enter the numbers" << "\nnumber 1 : ";
	cin >> numb1;
	cout << "number 2 : ";
	cin >> numb2;
	for (int i=max(numb1,numb2);i<=(numb1*numb2);i++ ){
		if ((i%numb1==0) && (i%numb2==0)){
			lcm = i;
			break;
		}
			}
	cout << lcm<<endl;
	return 0;
}
