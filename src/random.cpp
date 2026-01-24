#include <iostream>
#include <ctime>
using namespace std;
int main (){
    std::srand(std::time(nullptr));
    int indx=std::rand();
    cout << indx << "\n";
    int id=50+(indx%51);
    cout << id << "\n";
}
