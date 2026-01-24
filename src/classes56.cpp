#include <iostream>
using namespace std;
int main (){
    int v{5}; 
    int* ptr0 (&v); // points to v that is integer 
    const int* ptr1(&v); // points to const int 
    int* const ptr2(&v); // ptr is const 
    const int* const ptr3{&v}; // both are const 
    return 0;
}
