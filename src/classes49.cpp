#include <iostream>
class Adder{
    private:
        int m_value{};
        friend void print(const Adder &add){
            std::cout << add.m_value;
        }
    public:
        void add(int value){m_value+=value;}
};
/*void print(const Adder&add){
    std::cout << add.m_value;
}*/
int main (){
    Adder add;
    add.add(5);
    print(add);
    return 0;
}
