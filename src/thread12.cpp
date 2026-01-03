#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
std::mutex mtx ;
std::condition_variable cv;
std::queue<int>tasks;
bool done=0;
void worker(int id){
    while(true){
        std::unique_lock<std::mutex>lock(mtx);
        cv.wait(lock,[]{return!tasks.empty()||done;});
    if (done&&tasks.empty()){
        std::cout << " Worker " << id << "exiting\n";
        return ;
    }
    int task=tasks.front();
    tasks.pop();
    lock.unlock();
    std::cout << "worker " << id << " processing task " << task << "\n";
}
}
void add_task(int x){
    {
        std::lock_guard<std::mutex>lock(mtx);
        tasks.push(x);
    }
    cv.notify_one();
}

int main (){
    std::vector<std::thread>threads;
    for (int i=0;i<3;i++){
        threads.emplace_back(worker,i);
    }
    for (int i=1;i<=10;i++){
        add_task(i);
    }
    {
        std::lock_guard<std::mutex>lock(mtx);
        done=true;
    }
    cv.notify_all();
    for (auto &t:threads){
        t.join();
    }
    std::cout << "Main done\n";
    return 0;
}
