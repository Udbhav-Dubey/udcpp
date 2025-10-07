#include <iostream>
class Foo{
private:
    int m_value{4};
public :
    int &value(){return m_value;}
};
int main (){
    Foo f{};
    f.value()=5;
    std::cout << f.value();
    return 0;
}
