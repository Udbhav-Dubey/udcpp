#include <iostream>
class Something {
private:
        int m_x{};
public :
        Something(){
            m_x=5;
        }
        int getx()const{return m_x;}
};
int main (){
    const Something s{};
    std ::cout << s.getx();
    return 0;
}
