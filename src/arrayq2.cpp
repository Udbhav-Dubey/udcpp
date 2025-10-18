// program to print all negative elements in array
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "please enter the size of array\n";
	int n;
	cin >> n;
	vector <int> arr(n);
	cout << "enter the elements\n";
	for (int i=0;i<n;i++){
		cout << i+1 << " : " ;
		cin >> arr[i];
		//cout << endl;
	}
	for (int i=0;i<n;i++){
		if (arr[i]<0){
			cout << arr[i] << " ";
		}
	}
	return 0;
}
