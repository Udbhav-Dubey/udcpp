// program to find second largest number in array
#include <iostream>
#include <vector>
using namespace std;
int main (){
cout << "please enter the size of array\n";
	int n,sum=0;
	cin >> n;
	vector <int> arr(n);
	cout << "please enter the elements of array\n";
	for (int i=0;i<n;i++){
	cout << i+1 << " : " ;
	cin >> arr[i];
	}
	int max1=arr[0],max2=arr[0];
	for (int i=0;i<n;i++){
		if (arr[i]>max1){
		max2 = max1;
		max1 = arr[i];}
		else if (arr [i]> max2 && arr [i] < max1){
			max2= arr [i];
		}
	}
	cout << "first maximum is " << max1;
	cout << "2nd maximum is " << max2;
return 0;
}


