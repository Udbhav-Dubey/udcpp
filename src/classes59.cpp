#include <iostream>
using namespace std;

void nullify([[maybe_unused]] int* ptr1){
    ptr1=nullptr;
}
void nullify1([[maybe_unused]] int* &ptr2){
    ptr2=nullptr;
}
int main (){
    int x{5};
    int* ptr{&x};
    std::cout << "ptr is " << (ptr?"non null\n":"null\n");
    nullify(ptr);
    std::cout << "ptr is " << (ptr?"non null\n":"null\n");
    nullify1(ptr);
    std::cout << "ptr is " << (ptr?"non null\n":"null\n");
    return 0;
}
