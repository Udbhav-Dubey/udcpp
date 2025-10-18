#include <iostream>
using namespace std;
class parent {
    private :
        ~parent(){cout << "destructor\n";}
    public :
        parent (){cout << "contructor\n";}
        void destruct(){delete this;}
};
int main (){
    parent* p;
    p=new parent;
    p->destruct();
return 0;
}

