#include <iostream>
using namespace std;
static int  count =0;
class test{
    public :
        test(){
            count ++;
            cout << "contructor no is " << count << endl;
        }
        ~test(){
            cout << "destructor no is " << count << endl;
            count --;
            }
};
int main (){
    test t,t1,t2,t3;
return 0;
}
