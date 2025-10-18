#include <iostream>
using namespace std;
    class A{
        public :
            int a;
            A(int a){
                this->a=a;
                this->a=a+10;
            }
            void checker(int a){
                this->a=a;
                this->a=a+21;
                cout << "checker" << endl;
            }
            void display(){
                cout << "value " << this->a;
            }
    };
int main (){
    A o(10);
    o.checker(11 );
    o.display();
return 0;
}
