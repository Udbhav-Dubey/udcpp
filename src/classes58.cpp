#include <iostream>
using namespace std;
void printIdNumber(){
    cout << "no arguments\n";
}
void printIdNumber(const int *ptr){
    if (ptr){
        cout << *ptr << "\n";
    }
    else{
        cout << "empty ptr\n";
    }
}
int main (){
    printIdNumber();
    int id{34};
    printIdNumber(&id);
return 0;
}
