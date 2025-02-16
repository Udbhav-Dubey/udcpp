//program to print all unique elements in array
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "please input the size of array\n";
	int n;
	cin >> n;
	vector <int> arr(n);
	int freq[n]={0};
	cout << "now enter the elements\n";
	for (int i=0;i<n;i++){
		cin >> arr[i];
		freq[arr[i]]++;
	}
	cout << "unique elements are : ";
	for (int i=0;i<n;i++){
		if (freq[arr[i]]==1){
			cout << arr [i] << " ";
		}
	}
return 0;
}
