// program to merge two sorted array
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "enter the size of array 1\n";
	int n1;
	cin >> n1;
	vector <int> arr1(n1);
	cout << "now enter the elements of array 1 \n";
	for (int i=0;i<n1;i++){
		cin >> arr1[i];
	}
	cout << "enter the size of array 2\n";
	int n2;
	cin >> n2;
	vector <int> arr2(n2);
	for (int i=0;i<n2;i++){
		cin >> arr2[i];
	}
	vector <int> arr3(n1+n2);
	int j=0,i=0,k=0;
		while (i<n1 && j<n2){
			if (arr1[i]<=arr2[j]){
				arr3[k++]=arr1[i++];
			}
			else {arr3[k++]=arr2[j++];}
		}
		while (i<n1) {arr3[k++]=arr1[i++];}
		while (j<n2) {arr3[k++]=arr2[j++];}
	cout << "new array is \n";
	for (int i=0;i<n1+n2;i++){
		cout << arr3[i] << " ";
	}
return 0;
}
