#include <iostream>
#include <cmath>
using namespace std;
string prime (int num ){
    for (int i=2;i*i <=num;i++){
        if (num%i==0){return "not a prime number";}
        else {return "a prime number"}
    }
string arm (int num){
    for (int i=0;i<n;i++){
	int sum =0;
		int num =i;
	int digits = (int)log10(num)+1;
	while (num >0){
		int last_digit=num%10;
		sum += ceil(pow(last_digit,digits));
		num = num/10;
	}
	if (sum == i ){
		return "a armstrong number";
	}
    else {return "not a armstrong number "}
	} 
}
return "prime number";}
int main (){
    cout << "to check prime, armstrong,number\nplease enter the number : ";
    int num;
    cin >> num;
    cout << num << "is a " << prime(num) << endl ;
    cout << num << "is a " << arm(num) << endl ;

return 0;
}
