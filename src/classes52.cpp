#include <iostream>
using namespace std;
class Display;
class Storage{
    private:
        int vali{};
        float vald{};
    public:
        Storage(int i,float d):vali{i},vald{d} {};
        friend class Display;
};
class Display{
    private:
        bool show_int_first{};
    public:
        Display(bool flag):show_int_first{flag}{};
        void displayStorage(const Storage &stor){
            if (show_int_first==1){
                cout << stor.vali << "\n"<< stor.vald << "\n";
            }
            else {
                cout << stor.vald << "\n" << stor.vali << "\n";
            }
        }
        void set_int_first(bool f){
            show_int_first=f;
        }
};
int main (){
    Storage stor{5,6.7};
    Display display {false};
    display.displayStorage(stor);
    display.set_int_first(true);
    display.displayStorage(stor);

    return 0;
}
