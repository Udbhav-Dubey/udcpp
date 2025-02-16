//program to print all unique elements in array
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "please enter the size of array : ";
	int n;
	cin >> n;
	vector <int> arr(n);
	vector <int> freq(n);
	cout << "now enter the elements of array\n";
	for (int i=0;i<n;i++){
		cin >> arr[i];
		freq[i]=-1;
	}
	for (int i=0;i<n;i++){
		if (freq[i]==-1){
		int count =1;
		for (int j=i+1 ;j<n;j++){
			if (arr[i]==arr[j]){
				count ++;
				freq[j]=0;
			}
		}
		freq [i]=count ;
		}
	}
	for (int i=0;i<n;i++){
		if (freq[i]==1){
		cout << arr[i] << " ";
		}}
return 0;
}
