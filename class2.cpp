#include <iostream>
using namespace std;
class sphere {
    private :
    int radius;
    public : 
    double getRadius(){
        return radius;
    }
    void setRadius(int val){
        radius = val;
    }
    double surfacearea(){
        return 4 * 3.14 * radius *radius;
    }     
};
int main (){
    sphere obj;
    obj.setRadius(10);
    cout << "surface area is " << obj.surfacearea();
return 0;
}
