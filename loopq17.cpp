//program to check whether a number is palindrome or not.
#include <iostream>
using namespace std;
int main (){
	int reverse=0 ,numb;
	cout << "enter the number to check whether number is palindrome or not\n";
	cin >> numb;
	int number =numb;
	for (int i=0;numb!=0;i++){
	reverse = (reverse *10)+(numb%10);
	numb = numb/10;
	}
	if (number==reverse){
	cout << "palindrome\n";
	}
	else {cout << "not a palindrome\n";}
return 0;
}
