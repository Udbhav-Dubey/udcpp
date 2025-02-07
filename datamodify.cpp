#include <iostream>
using namespace std;
int main(){
	int x=123;
	float y=32.3232;
	double z =3421.421;
	short int a =312;
	long int b=42.324;
	long long int c =413.32132;
	long double d =43243432.432;
	unsigned int e=-321;
	cout << x << endl << sizeof(int)<<endl << y << endl << sizeof(float) << endl << z << endl << sizeof(int) << endl << a << endl << sizeof(short int ) <<b << endl <<sizeof(long int) ;
	cout << endl << c << endl << sizeof(long long int)<< endl << d << endl << sizeof(long double ) << endl << e  << endl << sizeof(unsigned int) << endl;
	return 0;
}
