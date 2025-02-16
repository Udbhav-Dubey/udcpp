//  program to find sum of all array elements.
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
	for (int i=0 ; i<n;i++){
	sum += arr[i];
	}
	cout << sum << endl;

return 0;
}
