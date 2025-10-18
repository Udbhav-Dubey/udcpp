#include <iostream>
using namespace std;
class values{
    protected : 
        int p,r,t;
};
class result : public values {
    public : 
        void setvalues(int pr,int rate,int time){
            p=pr;
            r=rate;
            t=time;
        }
        int getanswers(){
            return (p*r*t)/100;
        }
};
int main (){
    result obj;
    obj.pr,obj.rate,obj.time;
    cin >> obj.pr >> obj.rate >> obj.time;
   cout <<  obj.setvalues(obj.pr,obj,rate,obj.time);
return 0;
}
