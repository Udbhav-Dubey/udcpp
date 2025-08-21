#include <iostream>
struct Date{
    int year{};
    int month{};
    int day{};
    void incrementDay() const 
    {
        ++day;
    }
};
int main (){
    const Date today{2020,10,14};
    today.incrementDay();
return 0;
}
