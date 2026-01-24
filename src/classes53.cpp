#include <iostream>
using namespace std;
class Storage;
class Display{
    private:
        bool show_int_first{};
    public:
        Display(bool flag):show_int_first{flag}{};
        void displayStorage(const Storage &stor);
};
class Storage{
    private:
        int vali{};
        float vald{};
    public:
        Storage(int i,float f):vali{i},vald{f}{};
    friend void Display::displayStorage(const Storage &stor);
};
void Display::displayStorage(const Storage &stor){
    if (show_int_first){
        std::cout << stor.vali << "\n"<<stor.vald << "\n";
    }
    else {
        std::cout << stor.vald << "\n"<<stor.vali <<"\n";
    }
}

