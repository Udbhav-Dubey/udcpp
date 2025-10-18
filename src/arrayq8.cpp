//program to copy all elements of one array to another
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "enter the number of elements in array\n";
	int n,neg=0;
	cin >> n;
	vector <int> arr(n);
	cout << "enter the elements in the array : ";
	for (int i=0;i<n;i++){
		cin >> arr[i];
	}	
	vector <int> arr2(n);
	for (int i=0;i<n;i++){
	arr2[i]=arr[i];
	}
	cout << "2nd array is " << endl;
	for (int i=0;i<n;i++){
	cout << arr2[i] << " ";

	}
return 0;
}
