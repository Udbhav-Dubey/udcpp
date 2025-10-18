#include <iostream> 
#include <iomanip>
using namespace std;
int main (){
	cout << "Hello" << endl;
	cout << setw(10) << "hello" << endl;
	cout << setprecision(3) << 3.14159265 << endl;
	cout << fixed << 3.14159265 << endl;
	cout << scientific << 3.14159265 << endl;
	cout << showpoint << 42.0 << endl;
return 0;
}
