#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtxA;
std::mutex mtxB;
void worker1(){
    std::lock_guard<std::mutex>lockA(mtxA);
    std::cout << "Worker 1 locked A\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex>lockB(mtxB);
    std::cout << "worker 1 locked B\n";
}
void worker2(){
    std::lock_guard<std::mutex>lockB(mtxB);
    std::cout << "worker 2 locked B\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex>lockA(mtxA);
    std::cout << "worker 2 locked A\n";
}
int main (){
    std::thread t1(worker1);
    std::thread t2(worker2);
    t1.join();
    t2.join();
    std::cout << "work done in main \n";
}
