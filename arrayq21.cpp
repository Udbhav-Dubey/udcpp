#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout <<"enter the size of array\n";
	int n,temp=0;
	cin >> n;
	vector <int> arr(n);
	cout << "enter the elements of array \n";
	for (int i=0;i<n;i++){
		cin >> arr[i];
	}
	cout << "enter the times it has to be rotated left\n";
	int r;
	cin >> r;
	for (int i=0;i<r;i++){
		temp = arr[0];
		for (int j=0;j<n;j++){
			arr[j]=arr[j+1];
		}
		arr[n-1]=temp;
	}
	cout << "new array is \n";
	for (int i=0;i<n;i++){
		cout << arr[i]<< " ";
	}
return 0;
}
