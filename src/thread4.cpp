#include <iostream>
#include <thread>
void worker(int x,int &y){
    x+=10;
    std::cout << "x= " << x << "\n";
    y+=10;
}
int main (){
    int a=5;
    int b=20;
    std::thread t(worker,a,std::ref(b));
    t.join();
    std::cout << "a after thread : " << a << "\n";
    std::cout << "b after thread : " << b << "\n";
    return 0;
}

