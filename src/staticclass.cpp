#include <iostream>
using namespace std;
class UD {
	public :
		static int i ;
		UD(){
		};};
int UD::i=1;
int main () {
cout << UD::i<< endl ;
return 0;
}
