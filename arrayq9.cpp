// program to count negative elements in array
#include <vector>
#include <iostream>
using namespace std;
int main (){
cout << "enter the number of elements in array\n";
int n;
cin >> n;
vector <int> arr(n);
cout << "enter the elements of array : ";
	for (int i=0;i<n;i++){
		cin >> arr[i];
}
cout << "enter the element to insert : ";
int el,n1;
cin >> el;
cout << "enter the index where it has to inserted : ";
cin >> n1;
	for (int i=n;i>=n1;i--){
	arr[i]=arr[i-1];
	}
arr [n1-1]=el;
n++;
cout << "new array is : ";
for (int i=0;i<n;i++){
	cout << arr[i] << " ";
}
return 0;
}
