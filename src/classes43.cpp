#include <algorithm>
#include <iostream>
class Foo{
private:
        int m_x{};
        int m_y{};
public:
        Foo(int x,int y):
            m_y{std::max(x,y)},m_x{m_y} // issue hai iss line mein
            {
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
