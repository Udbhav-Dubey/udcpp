#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>
//#include <format>
void e1(){
    std::chrono::milliseconds my_duration(500);
    std::cout << "my_duration: "<<my_duration.count() << " ms \n";
    std::chrono::microseconds us(500);
    std::chrono::seconds sec(5);
    std::chrono::hours hr(1);
    std::chrono::nanoseconds ns(1000);
    std::chrono::minutes min (2);
    std::cout << "time is : " << hr.count() << " hour : " << min.count()  << " min :" << sec.count() << " sec : " << ns.count() << "nanoseconds \n";

}
void e2(){
    std::chrono::seconds sec(10);
    std::chrono::milliseconds ms(500);
    auto total= sec + ms;
    std::cout << "10 sec + 500 ms is " << total.count()<< "ms\n";
    auto tripiled=sec*3;
    std::cout << "10sec*3 is " << tripiled.count()<<"seconds\n";
}
void e3(){
    std::chrono::seconds sec(3);
    auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(sec);
    std::cout << "3 seconds = " << ms.count()<<" milliseconds\n";
    auto us=std::chrono::duration_cast<std::chrono::microseconds>(sec);
    std::cout << "3 seconds = " << us.count()<<" microseconds\n";
}
void e4(){
    using namespace std::chrono_literals;
    auto d1=250ms;
    auto d2=5s;
    auto d3=2min;
    auto total=d1+d2+d3;
    std::cout << "total: " << total.count()<<" milliseconds\n";
}
void e5(){
    auto now=std::chrono::steady_clock::now();
    auto epoch_time=now.time_since_epoch();
    std::cout <<"nanoseconds since epoch : " << epoch_time.count() << "\n";
}
void e6(){
    long long sum=0;
    auto start=std::chrono::high_resolution_clock::now();
    for (int i=0;i<1000000;i++){
        sum+=i;
    }
    auto end=std::chrono::high_resolution_clock::now();
    auto duration=end-start;
    auto us=std::chrono::duration_cast<std::chrono::microseconds>(duration);
    std::cout <<"Loop took : " << us.count() << "microseconds\n";
}
void e7(){
    using namespace std::chrono_literals;
    using namespace std::chrono;
    auto sys_start=std::chrono::system_clock::now();
    auto steady_start=std::chrono::steady_clock::now();
    auto highres_start=std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(100ms);
    auto sys_end=std::chrono::system_clock::now();
    auto steady_end=std::chrono::steady_clock::now();
    auto highres_end=std::chrono::high_resolution_clock::now();
    std::cout << "System: " << duration_cast<milliseconds>(sys_end - sys_start).count() << "ms\n";
    std::cout << "Steady: " << duration_cast<milliseconds>(steady_end - steady_start).count() << "ms\n";
    std::cout << "HighRes: " << duration_cast<milliseconds>(highres_end - highres_start).count() << "ms\n";
    std::cout << "steady_clock::is_steady = " << steady_clock::is_steady << "\n";
    std::cout << "high_resolution_clock::is_steady = " << high_resolution_clock::is_steady << "\n";
}
void e8(){
    std::cout << "waiting for 1 second : ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Done waiting ";
}
void e9(){
    auto start=std::chrono::steady_clock::now();
    std::cout << "Timer started ...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    auto now=std::chrono::steady_clock::now();
    auto elapsed=now-start;
    auto ms=std::chrono::duration_cast<std::chrono::milliseconds>(elapsed);
    std::cout << "elapsed time : " <<ms.count() << "ms\n";
}
void e10(){
    using namespace std::chrono_literals;
    auto start=std::chrono::steady_clock::now();
    auto timeout=200ms;
    std::this_thread::sleep_for(100ms);
    auto now=std::chrono::steady_clock::now();
    auto elapsed=now-start;
    if (elapsed>timeout){
        std::cout << "time exceeded!\n";
    }
    else{
        std::cout << "Still within timeout \n";
    }
}
void e11(){
    auto now=std::chrono::system_clock::now();
    std::time_t now_c =std::chrono::system_clock::to_time_t(now);
    std::cout << "current time : "<<std::ctime(&now_c);
}

int main (){
    e1();
    e2();
    e3();
    e4();
    e5();
    e6();
    e7();
    e8();
    e9();
    e10();
    e11();
    return 0;
}
