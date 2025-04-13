#include <iostream>
class test {
    static int a;
    public :
    void func(int a){std ::cout << test::a;}
};
int test ::a=1;
int main (){
    test obj;
    obj.func(3);
return 0;
}
