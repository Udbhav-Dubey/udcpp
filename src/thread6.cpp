#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtx;
void worker(int id){
    std::lock_guard<std::mutex>lock(mtx);
    std::cout << "Worker " << id << " in critical section\n";
}
int main (){
    std::thread t1(worker,1);
    std::thread t2(worker,2);
    t1.join();
    t2.join();
    return 0;
}
