#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <thread>
std::mutex mtx;
void worker(int i,std::queue<int>&q){
    while(true){
        int task;
        {
            std::lock_guard<std::mutex>lock(mtx);
            if (q.empty()){break;}
            task=q.front();
            q.pop();
        }
        std::cout << "thread " << i << " working on  " << task << "\n";
    }
}
int main (){
    std::cout << "enter the last integer in the queue : ";
    int x;
    std::cin>>x;
    std::queue<int>q;
    for (int i=1;i<=x;i++){
        q.push(i);
    }
    std::cout << "how many threads you want : ";
    int n;
    std::cin>>n;
    std::vector<std::thread> threads;
    for (int i=0;i<n;i++){
        threads.emplace_back(worker,i,std::ref(q));
    }
    for (auto &t:threads){
        t.join();
    } 
    std::cout << "end of main\n";
    return 0;
}
