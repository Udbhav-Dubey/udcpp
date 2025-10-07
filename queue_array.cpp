#include <iostream>
using namespace std;
#define Max 100
class Queue{
    private:
        int arr[Max];
        int rear;
        int front;
    public :
        Queue(){
            front =0;
            rear=-1;
        }
        bool isEmpty(){
            return front>rear;
        }
        bool isFull(){
            return rear==Max-1;
        }
        void enqueue(int value){
            if (isFull()){
                cout << "Queue is full\n";
                return ;
            }
            rear++;
            arr[rear]=value;
            cout << value << "appended\n";
        }
        int dequeue(){
            if (isEmpty()){
                cout << "its empty \n";
                return -1;
            }
            int value=arr[front];
            front++;
            return value;
        }
        int peek(){
            if (isEmpty()){
                cout << "Queue is empty!\n";
                return -1;
            }
            return arr[front];
        }
        void display (){
            if (isEmpty()){
                cout << "Queue is empty \n";
                return ;
            }
            cout << "Queue elements : ";
            for (int i=front;i<=rear;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
int main (){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Dequeued : " << q.dequeue() << endl;
    cout << "Front element " << q.peek()<<endl;
    q.display();
    return 0;
}
