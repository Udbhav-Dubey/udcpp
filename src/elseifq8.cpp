//program to check vowel or consonant
#include <iostream>
using namespace std;
int main (){
	char ch;
	cout << "please enter the character\n";
	cin >> ch;
	if (ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U'){
		cout << "vowel\n";
	}
	else {cout << "consonents\n";}
return 0;
}
