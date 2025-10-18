#include <iostream>
#include <string>
struct Person{
    std::string name{};
    int age{};
    void kills(const Person&person){
        std::cout << name << " kills " << person.name << "\n";
    }
};
int main (){
Person joe{"Joe",29};
Person kate{"Kate",27};
joe.kills(kate);
return 0;
}
