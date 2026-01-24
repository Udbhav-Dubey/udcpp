#include <iostream>
using namespace std;
class Something{
    private:
        static inline int s_value {1};
    public:
        static int getValue(){return s_value;}
};
int main (){
    cout << Something::getValue()<<"\n";
    return 0;
}
