#include <iostream>
struct Employee{
    int id{};
    int age{};
    double wage{};
};
int main (){
    Employee joe{};
    joe.id=14;
    joe.age=32;
    joe.wage=60000.0;
    Employee frank{};
    frank.id=15;
    frank.age=28;
    frank.wage=45000.0;
    int totalAge{joe.age+frank.age};
    std::cout << "Joe and Frank have lived " << totalAge << " total years\n";
    if (joe.wage>frank.wage){
        std::cout <<"Joe makes more than frank\n";
    }
    else if (joe.wage<frank.wage){
        std::cout << "joe makes less than frank\n";
    }
    else {
        std::cout << "Joe and frank make the same amount\n";
    }
    frank.wage+=5000;
    ++joe.age;
    return 0;
}
