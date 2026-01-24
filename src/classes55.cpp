#include <iostream>
using namespace std;
class Calc{
    int m_value{};
    public:
    Calc& add(int value){m_value+=value;return *this;}
    Calc& sub(int value){m_value-=value;return *this;}
    Calc& multi(int value){m_value*=value;return *this;}
    int getValue()const {return m_value;}
};
int main (){
    Calc calc{};
    calc.add(6).sub(2).multi(5);
    std::cout << calc.getValue() << "\n";
    return 0;
}
