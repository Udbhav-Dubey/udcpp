#include <iostream>
#include <thread>
#include <vector>
void worker(int i){
    std::cout << "thread working :  " << i << "\n";
}
int main (){
    std::vector<std::thread> threads;
    for (int i=0;i<4;i++){
        threads.emplace_back(worker,i);
    }
    for (auto &t:threads){
        t.join();
    }
    std::cout << "All work done \n";
    return 0;
}
