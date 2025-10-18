#include <iostream>
struct Date{
    int year{};
    int month{};
    int day{};
    void print() const{
        std::cout << year << "/" << month << "/" << day ;
    }
};
void dosomething(const Date& date){
    date.print();    
}
int main (){
    Date today{2020,10,14};
    today.print();
    dosomething(today);
    return 0;
}
