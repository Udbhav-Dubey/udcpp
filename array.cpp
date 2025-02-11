#include <iostream>
using namespace std;
int main (){
	int arr[]={123,321,4343,53};
	cout << "1st: " << *arr << endl;
	cout << "2nd: " << *(arr+1) << endl;
	cout << "3rd: " << *(arr+2) << endl;
	cout << "4th: " << *(arr+3) << endl;
return 0;
}
