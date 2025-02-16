//program count total duplicate elements in array
#include <iostream>
#include <vector>
using namespace std;
int main (){
	cout << "please input the size of array\n";
	int n,count=0;
	cin >> n;
	vector <int> arr(n);
	int freq[n]={0};
	cout << "now enter the elements\n";
	for (int i=0;i<n;i++){
		cin >> arr[i];
		freq[arr[i]]++;
	}
//	cout << "unique elements are : ";
	for (int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (arr[i]==arr[j]){
			count++ ;	
			break;
			}	
			}}
	
		cout << "duplicates : " << count << endl;
return 0;
}
