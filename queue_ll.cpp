#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(NULL){}
};
class Queue{
    private:
        Node*front;
        Node*rear;
    public:
        Queue(){
        front=rear=NULL;
        }
        bool isEmpty(){
            return front==NULL;
        }
        void enqueue(int value){
            Node* newnode=new Node(value);
            if (rear==NULL){
                front=rear=newnode;
            }
            else {
                rear->next=newnode;
                rear=newnode;
            }
            cout << value << "enqueued\n";
        }
        int dequeue(){
            if (isEmpty()){
                cout << "queue is empty";
                return -1;
            }
            Node*temp=front;
            int val=temp->data;
            front=front->next;
            if (front==NULL){
                rear=NULL;
            }
            delete temp;
            return val;
        }
        int peek(){
            if (isEmpty()){
                cout << "Queue is empty! nothing to peek\n";
                return -1;
            }
            return front->data;
        }
        void display(){
            if (isEmpty()){
                cout << "Queue is empty!\n";
                return ;
            }
            cout << "Queue : ";
            Node*temp=front;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp=temp->next;
            }
            cout << "\n";
        }
};
int main (){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Dequeued : " << q.dequeue() << endl;
    cout << "Front element : " << q.peek() << endl;
    q.enqueue(40);
    q.enqueue(50);
    q.display();
return 0;
}
