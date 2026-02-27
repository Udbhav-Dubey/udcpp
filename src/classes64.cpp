#include <iostream>
class Base{
    private:
        int dpriv;
    public:
        int dpub;
    protected:
        int dprotec;
};
class Derived:private Base{
    public:
        Derived(){
            dpub=1;
            dprotec=2;
            dpriv=3; // this will not work 
        }
};
int main (){
    Base base;
    base.dpriv;// will not work
    base.dpub;// will work 
    base.dprotec// will not work
    Derived d;
    // for derived nothing will work everything becomes public
    return 0;
}
