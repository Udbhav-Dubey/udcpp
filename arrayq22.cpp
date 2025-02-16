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
	cout << "enter the times it has to be rotated right\n";
	int r;
	cin >> r;
	for (int i=0;i<r;i++){
		temp = arr[n-1];
		for (int j=n-1;j>0;j--){
			arr[j]=arr[j-1];
		}
		arr[0]=temp;
	}
	cout << "new array is \n";
	for (int i=0;i<n;i++){
		cout << arr[i]<< " ";
	}
return 0;
}
