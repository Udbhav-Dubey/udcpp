#include <thread>
#include <mutex>
#include <iostream>
#include <queue>
#include <condition_variable>
std::mutex mtx;
std::condition_variable cv;
std::queue<int>q;
bool done=0;
void consumer(){
    std::unique_lock<std::mutex>lock(mtx);
    while(q.empty()&&!done){
        cv.wait(lock);
    }
    if (!q.empty()){
        int value=q.front();
        q.pop();
        std::cout << "consumed " << value << "\n";
    }
}
void producer(){
    {
        std::lock_guard<std::mutex>lock(mtx);
        q.push(42);
    }
    cv.notify_one();
}
int main (){
    std::thread t1(consumer);
    std::thread t2(producer);
    t2.join();
    t1.join();
    return 0;
}
