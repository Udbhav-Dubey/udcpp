#include <iostream>
using namespace std;
    int main (){
            int x=12;
            int *px=&x;
            cout << "x is " << x << endl << "pointer is " << px << endl;
            cout << "value is " << *px << endl << "the address of x is " << &x << endl << "the address of pointer is " << &px << endl; 
        return 0;
    }
