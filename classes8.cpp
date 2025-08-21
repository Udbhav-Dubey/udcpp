#include <iostream>
struct Date{
    int year{};
    int month{};
    int day{};
    void incrementDay(){
        ++day;
    }
};
int main (){
    const Date today{2020,10,14};
    today.day+=1; // compiler error 
    today.incrementDay(); // compiler error cannot mess with const
    std:: cout << today.year << " " << today.month << " " << today.day << std::endl;
return 0;
}
