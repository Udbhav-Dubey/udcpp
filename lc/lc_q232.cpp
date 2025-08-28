class MyQueue {
private:
    stack<int>s1;
    stack<int>s2;
public:
    MyQueue() {
    }
    void push(int x) {
    s2.push(x);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        swap(s1,s2);        
    }
    int pop() {
        int temp=s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
