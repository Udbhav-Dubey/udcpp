#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "enter the size of array\n";
	int n;
	cin >> n;
	vector <int> arr(n);
	cout << "now enter the elements of array\n";
	for (int i=0;i<n;i++){
		cin>> arr[i];
	}
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (arr[i]==arr[j]){
				for (int k=j;k<n;k++){
					arr[k]=arr[k+1];
				}
				n--;
				j--;
			}
		}
	}
	cout << "array after deleting the elements\n";
	for (int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
return 0;
}
