//print all prime numbers between 1 to n
#include <iostream>
using namespace std;
int main (){
	int numb;
	cout << "please enter number to find till prime number till number \n";
	cin >> numb;
	for (int i=2;i<=numb;i++){
		int flag =0;
		for (int j=2;j<=(i/2);j++){
			if (i%j==0){flag=1;break;}
		}
		if (flag ==0){cout << i << " ";}
	}
return 0;
}
