//program to count negative elements in array
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
	for (int i=0;i<n;i++){
	if (arr[i]<0){
		neg++;
	}
	}
	cout << "number of negative numbers : " << neg << endl;
return 0;
}
