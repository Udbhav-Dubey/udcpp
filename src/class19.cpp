#include <iostream>
class test {
    public : 
        test(){
            std :: cout << "constructor\n";
        }
        ~test(){
            std ::cout << "destructor\n";
        }
};
int main (){
test t;
return 0;
}
