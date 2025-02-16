// program to find maximum and minimum element in array
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
	int max = arr[0];
	int min = arr[0];
 			for (int j=1;j<n;j++){
			if (arr[j]>max){
				max = arr[j];
			}
			if (arr[j]<min){
				min = arr [j];
			}
		}
cout << "the maximum is " << max<< endl;
cout << "the minimum is " << min << endl;
return 0;
}
