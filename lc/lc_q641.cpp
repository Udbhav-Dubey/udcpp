#include <bits/stdc++.h>
using namespace std;
class MyCircularDeque {
public:
    vector <int> arr;
    int front,rear,size;
    MyCircularDeque(int k) {
        size=k;
        front=-1;
        rear=-1;
        arr.resize(k);
    }
    
    bool insertFront(int value) {
        if (isFull()){return 0;} 
        if (isEmpty()){front=0;rear=0;}
        else {
            front=(front-1+size)%size;
        }
        arr[front]=value;
        return 1;
    }
    
    bool insertLast(int value) {
       if (isFull()){return 0;}
       if (isEmpty()){
        front=rear=0;}
       else {
       rear=(rear+1)%size;}
       arr[rear]=value;
       return 1;
    }
    
    bool deleteFront() {
        if (isEmpty()){return 0;}
        if (front==rear){
            front=rear=-1;
        }
        else {
        front=(front+1)%size;}
        return 1;
    }
    
    bool deleteLast() {
        if (isEmpty()){return 0;}
        if (front==rear){
            front=rear=-1;
        }
        else {
        rear=(rear-1+size)%size;}
        return 1;
    }
    
    int getFront() {
        if (isEmpty()){return -1;}
        return arr[front];
    }
    
    int getRear() {
        if (isEmpty()){return -1;}
        return arr[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return ((rear+1)%size)==front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main (){
return 0;
}
