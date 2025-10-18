#include <iostream>
#include <optional>
class Fraction {
private:
    int m_numerator{0};
    int m_denominator{1};
    Fraction(int numerator,int denominator):
        m_numerator{numerator},m_denominator{denominator}
    {
    }
public:
    friend std::optional<Fraction> createFraction(int numerator,int denominator);
};
std:: optional<Fraction> createFraction(int numerator,int denominator){
    if (denominator==0){
        return {};}
    return Fraction{numerator,denominator};
    
}
int main (){
    auto f1{createFraction(0,1)};
    if (f1){
        std::cout << "Fraction Created\n";
    }
    auto f2{createFraction(0,0)};
    if (!f2){
        std::cout << "Bad fraction\n";
    }
}
