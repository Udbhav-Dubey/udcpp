// program to declare, initialize, input and print array elements
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "please input the size of array \n";
	int n ;
	cin >> n;
	vector<int> arr(n);
	cout << "now input the elments of array\n";
	for (int i=0;i<n;i++){
		cout << i << " : ";
		cin >> arr [i] ; 
	}
	for (int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	return 0;
}
