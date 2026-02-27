#include <iostream>
class A{
    public:
        A(int a){
            std::cout << "A constructor " << a << "\n";
        }
};
class B:public A{
    public:
        B(int a,int b):A{a}{
            std::cout << "B constructor " << b << "\n";
        }
};
class C:public B{
    public:
        C(int a,int b,int c):B{a,b}{
            std::cout << "C constructor " << c << "\n";
        }
};
class D:public C{
    public:
        D(int a,int b,int c,int d):C{a,b,c}{
            std::cout << "D constructor " << d << "\n";
        }
};
int main (){
    D d(1,2,3,4);
    return 0;
}
