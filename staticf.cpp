#include <iostream>
using namespace std;
void f(){
static int count =0;
count ++;
cout << count << endl;
}
int main (){
	for (int i=0;i<5;i++){
		f();
	}
return 0;
}
