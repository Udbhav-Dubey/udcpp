// program to count even and odd elements in array
#include <iostream>
#include <vector>
using namespace std;
int main (){
cout << "please enter the size of array\n";
int n,even=0,odd=0;
cin >> n;
cout << "please enter the elements of array\n";
vector <int> arr(n);
for (int i=0;i<n;i++){
	cin >> arr[i];
}
for (int i=0;i<n;i++){
	if (arr[i]%2==0){even++;}
	else {odd++;}
}
cout << "even elements are : " << even << endl;
cout << "odd elements are : " << odd << endl;
return 0;
}
