#include <iostream>
using namespace std;
string well(int num){
    return (num%2==0) ? "even" : "odd";
}
int main (){
    cout << "C program to check even or odd using functions\nenter the number : ";
    int num;
    cin >> num;
    cout << "your answer is " << well(num) << endl;
return 0;
}
