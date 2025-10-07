#include <iostream>
class Foo{
private:
        int m_x{0};
        int m_y{1};
public :
        Foo(int x,int y){
            m_x=x; //  incorrect : this is an assignment , not an inittialization
            m_y=y; //  incorrect : this is an assignment , not an inittialization 
        }
        void print()const{
            std::cout << "Foo(" << m_x << "," << m_y << ")\n";
        }
};
int main (){
    Foo foo{6,7};
    foo.print();
    return 0;
}
