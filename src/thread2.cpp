#include <iostream>
#include <thread>
#include <chrono>
void cook(std::string dish){
    std::cout << "Cooking " << dish << "..\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    std::cout << dish << "ready!\n";
}
int main (){
    std::thread chef1(cook,"pasta");
    std::thread chef2(cook,"Salad");
    std::thread chef3(cook,"soup");
    chef1.join();
    chef2.join();
    chef3.join();
    std::cout << "Dinner is served!\n";
    return 0;
}
