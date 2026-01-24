#include <iostream>
using namespace std;
void printByValue(string val){
    cout << val << "\n";
}
void printByRef(string &ref){
    cout << ref << "\n";
}
void printByaddr(string *ptr){
    cout << *ptr << "\n";
}
int main (){
    string x{"ud"};
    printByRef(x);
    printByValue(x);
    printByaddr(&x);
    return 0;
}
