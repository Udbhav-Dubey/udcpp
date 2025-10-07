#include <iostream>
class Foo{
private:
    int m_x{};
    int m_y{2};
    int m_z;
public :
    Foo(int x):
        m_x{x}
    {
        std::cout << "Foo constructed\n";
    }
    void print() const {
        std::cout << "Foo(" << m_x << ", " << m_y <<"," << m_z << ")\n";
    }
};
int main (){
    Foo foo{6};
    foo.print();
    return 0;
}
