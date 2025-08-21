#include <iostream>
struct Date{
    int year{};
    int month{};
    int day{};
    void print() const {
        std::cout << year << "/" << month << "/" << day ;
    }
};
int main (){
    const Date today{2020,10,14};
    today.print();
    return 0;
}
