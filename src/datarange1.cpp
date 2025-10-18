#include <iostream>
#include <limits>
using namespace std;
int main (){
	cout << "Short int range from : " << numeric_limits<short int> :: min() << " to " << numeric_limits<short int > :: max() << endl;
	cout << "int range from : " <<numeric_limits<int> :: min () << " to " << numeric_limits<int> :: max() <<endl;
	cout << "long int ranges from : " << numeric_limits<long> :: min() << " to " << numeric_limits<long> :: max() << endl;
return 0;
}
