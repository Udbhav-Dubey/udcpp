class MyCircularQueue {
    int *arr;
    int front, rear, size;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        front = rear = -1;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return true;
    }

    int Front() { return isEmpty() ? -1 : arr[front]; }
    int Rear() { return isEmpty() ? -1 : arr[rear]; }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % size == front; }

    ~MyCircularQueue() { delete[] arr; }
};

