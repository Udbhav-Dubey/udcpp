// program to delete element from an array
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "please enter the number of elements in the array\n";
	int n;
	cin >> n;
	vector <int> arr (n);
	cout << "now enter the elements in the array\n";
	for (int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << "now enter the element to delete\n";
	int del;
	cin >> del;
	for (int i=del-1;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	cout << "the new array is\n";
	n--;
	for (int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
return 0;
}
