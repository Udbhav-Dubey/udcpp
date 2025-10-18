// program to sort array in ascending or descending order
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
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout << "sorted array is\n";
	for (int i=0;i<n;i++){
		cout << arr[i] << " " ;
	}
return 0;
}
