#include <iostream>
#include <thread>
#include <chrono>
void worker(){
    std::cout << "working thread\n";
}
int main (){
    std::thread t(worker);
    t.join();
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Main done\n";
    return 0;
}
