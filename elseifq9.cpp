//program to check whether a character is alphabet, digit or special character
#include <iostream>
using namespace std;
int main (){
	cout << "please enter the character\n";
	char ch;
	cin >> ch;
	 if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        cout << "alphabet.";
    }
    else if(ch >= '0' && ch <= '9')
    {
        cout << "digit.";
    }
    else 
    {
        cout << "special character";
    }
    return 0;
}
