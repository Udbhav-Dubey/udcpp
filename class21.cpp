#include <iostream>
using namespace std;
class test {
    public : 
        test (){
            cout << "constructor\n";
        }
    private :
        ~test(){
            cout << "destructor\n";
        }
};
int main (){
   test* t = new test;
   delete t;
    return 0;
}
