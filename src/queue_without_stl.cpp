#include <iostream>
using namespace std;
const int Max=100;
class Queue{
    private:
        int arr[Max];
        int front , rear;
    public :
        Queue(){
            front=0;
            rear=-1;
        }
        bool isFull(){
            return rear==Max-1;
        }
        bool isEmpty(){
            return front>rear;
        }
        void enqueue(int value){
            if(isFull()){
                cout << "the queue is full ! cannot add " << endl;
                return ;
            }
            arr[++rear]=value;
            cout << value << "enqueued" << endl;
        }
        int dequeue(){
            if (isEmpty()){
                cout << "queue is empty! cannot remove " << endl;
                return -1;
            }
            return arr[front++];
        }
        int peek(){
            if (isEmpty()){
                cout << "queue is empty!nothing to peek\n";
                return -1;
            }
            return arr[front];
        }
        void display(){
            if (isEmpty()){
                cout << "Queue is empty !\n";
                return ;
            }
            cout << "Queue is :" ;
            for (int i=front;i<=rear;i++){
                cout << arr[i] << " ";
                cout << "\n";
            }
        }
};
int main (){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element : " << q.peek() << endl;
    q.display();
    return 0;
}
