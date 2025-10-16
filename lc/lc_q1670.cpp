#include <bits/stdc++.h>
using namespace std;
class FrontMiddleBackQueue {
public:
    deque<int> d1;
    deque<int> d2;
    FrontMiddleBackQueue() {
    }
    void balance (){
         while(d1.size()>d2.size()){
            d2.push_front(d1.back());
            d1.pop_back();
        }
         while(d2.size()>d1.size()+1){
            d1.push_back(d2.front());
            d2.pop_front();
        }
    }
    void pushFront(int val) {
        d1.push_front(val);
        balance();
    }
    void pushMiddle(int val) {
        if (d1.size()<d2.size()){
            d1.push_back(val);
        }
        else {
            d2.push_front(val);
        }
        balance();
    }
    void pushBack(int val) {
        d2.push_back(val);
        balance();
    }
    int popFront() {
        if (d1.empty()&&d2.empty()){return -1;}
        int temp;
        if (!d1.empty()){
            temp=d1.front();
            d1.pop_front();
        }
        else{temp=d2.front();
            d2.pop_front();
        } 
        balance();
        return temp;
    }
    
    int popMiddle() {
        if (d1.empty()&&d2.empty()){return-1;}
        int temp;
        if (d2.size()>d1.size()){
        temp=d2.front();
        d2.pop_front();
        }
        else {
            temp=d1.back();
            d2.pop_back();
        }
        balance();
        return temp;
    }
    
    int popBack() {
        if (d2.empty()&&d1.empty()){return -1;}
        int temp=d2.back();
        if (!d2.empty()){
            val=d2.back();
            d2.pop_back();
        }
        else {
            val=d1.back();
            d1.pop_back();
        }
        balance();
        return temp;
    }
};
/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
int main (){
return 0;
}
