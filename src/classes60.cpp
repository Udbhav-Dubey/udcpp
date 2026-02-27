#include <string>
#include <iostream>
class Person{
private:
    std::string name{};
    int age{};
public:
    Person(std::string n="",int a=0):name{n},age{a} {}
    const std::string&getName() const{return name;}
    int getAge()const {return age;}
};
class BaseballPlayer:public Person{
    private:
        double batting_average{};
        int homeruns{};
    public:
        BaseballPlayer(std::string n="",int a=0,double ba=0.0,int h=0)
        :Person{n,a},batting_average{ba},homeruns{h}{}
    double getbattingAverage()const {return batting_average;}
    int getHomeRuns()const {return homeruns;}
};
class Employee:public Person{
    public:
        double salary{};
        long id{};
        Employee(double s=0.0,long d=0):salary{s},id{d} {}
};
class SuperVisor:public Employee{
    public:
        long m_overseesid[5]{};
};
int main (){
    BaseballPlayer p1{"player 1",32,0.324,42};
    std::cout << p1.getName() << "\n";
    std::cout << p1.getAge() <<"\n";
    std::cout << p1.getbattingAverage()<<"\n";
    std::cout << p1.getHomeRuns()<<"\n";
    return 0;
}
