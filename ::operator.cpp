#include <iostream>
using namespace std;
int x=10;
namespace N {
	int val =10;
};
class A {
	public : 
		void fun();
}a;
void A::fun (){
	cout << "fun()" << endl;
}
int main(){
	cout << N ::val << endl;
	cout << :: x << endl;
	
	a.fun ();
return 0;
}
