#include <iostream>
using namespace std;
class box{
    private :
        static int length;
        static int breadth;
        static int height;
    public:
        static void print () {
            cout << "the value of length is : " << length << endl;
            cout << "the value of breadth is : " << breadth << endl;
            cout << "the value of height is : " << height << endl;
        }
};
int box::length=10;
int box::breadth=20;
int box::height=30; 
int main (){
    box b;
    box::print();
return 0;
}
