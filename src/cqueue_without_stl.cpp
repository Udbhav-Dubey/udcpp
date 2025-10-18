#include <bits/stdc++.h>
using namespace std;
    const int Max=100;
class CircularQueue{
    private:
            int arr[Max];
            int front , rear,size;
    public:
            CircularQueue(){
                front =0;
                rear=-1;
                size=0;
            }
    bool isFull(){
        return size==Max;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(int value){
        if (isFull()){
            cout << "queue is full " << value <<  endl;
            return ;
        }
        rear=(rear+1)%Max;
        arr[rear]=value;
        size++;
        cout << value << "enqueued\n";
    }
int dequeue(){
    if(isEmpty()){
        cout << "empty cannot delete " << endl;
        return -1;
    }
    int val=arr[front];
    front=(front+1)%Max;
    size--;
    return val;    
    }
    int peek(){
    if (isEmpty()){
        cout << "Queue is Empty! nothing to peek\n";
        return -1;
    }
    return arr[front];
}
    void display(){
        if (!isEmpty()){
            cout << "Queue is empty \n";
            return ;
        }
        cout << "Queue: ";
        for (int i=0;i<size;i++){
            int index=(front+1)%Max;
            cout << arr[index] << " ";
        }
        cout << "\n";
    }
};
int main (){
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Dequeued : " << q.dequeue()<<endl;
    cout << "front element " <<q.peek()<<endl;
    q.enqueue(40);
    q.enqueue(50);
    q.display();
return 0;
}
