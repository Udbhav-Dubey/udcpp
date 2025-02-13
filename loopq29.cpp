//find of all prime factors between 1 to n
#include <iostream>
using namespace std;
int main (){
	int numb;
	cout << "please enter number to find all prime factors till number \n";
	cin >> numb;
	for (int i=2;i<=numb;i++){
		int flag =0;
		for (int j=2;j<=(i/2);j++){
			if (i%j==0){flag=1;break;}
		}
		if (flag ==0){if (numb%i==0){cout << i << " ";}}
	}
//	cout << "sum is : " << sum << endl;
return 0;
}
