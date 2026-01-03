#include <iostream>
#include <thread>
#include <mutex>
std::mutex mtxA;
std::mutex mtxB;
int worker(int &i){
    std::lock(mtxA,mtxB);
    std::lock_guard<std::mutex>lockA(mtxA,std::adopt_lock);
    std::lock_guard<std::mutex>lockB(mtxB,std::adopt_lock);
    std::cout << "worker " << i << " working \n";
    i+=10;
    return i;
}
int main (){
    int a=1,b,c;
    std::thread t1(worker,std::ref(a));
    std::thread t2(worker,std::ref(a));
    std::cout << "b comes out to be " << b << "\n";
    std::cout << "c comes out to be " << c << "\n";
    t1.join();
    t2.join();
    std::cout << "main done\n";
    return 0;
}
