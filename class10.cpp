#include <iostream>
using namespace std;
class major;
class minor{
    public :
    int function(major &t,int a);
};
class major {
    private : 
        int x;
    public :
        major (){
            x=69;
        }
        friend int minor :: function(major &,int a);
};
int minor :: function(major & t,int a){
return a * t.x;
}
int main (){
    major object;
    minor obj1;
   cout <<  obj1.function(object,10) << endl;
return 0;
}
