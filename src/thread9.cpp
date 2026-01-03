#include <thread>
#include <iostream>
#include <mutex>
std::mutex mtxA;
std::mutex mtxB;
void worker1(){
    std::lock_guard<std::mutex>lockA(mtxA);
    std::cout << "worker 1 locked A\n";
    std::lock_guard<std::mutex>lockB(mtxB);
    std::cout << "worker 1 locked B\n";
}
void worker2(){
    std::lock_guard<std::mutex>lockA(mtxA);
    std::cout << "worker 2 locked A\n";
    std::lock_guard<std::mutex>lockB(mtxB);
    std::cout << "worker 2 locked B\n";
}
int main (){
    std::thread t1(worker1);
    std::thread t2(worker2);
    t1.join();
    t2.join();
    std::cout << "end of main\n";
    return 0;
}
