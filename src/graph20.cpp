#include <iostream>
#include <vector>
class MinPQ{
    std::vector<int>heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    void heapifyUp(int i){
        while(i>0&&heap[parent(i)]>heap[i]){
            std::swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    void heapifyDown(int i){
        int n=heap.size();
        while(true){
            int l=left(i);
            int r=right(i);
            int smallest=i;
            if (l<n&&heap[l]<heap[smallest]){
                smallest=l;
            }
            if (r<n&&heap[r]<heap[smallest]){
                smallest=r;
            }
            if (smallest==i)break;
            std::swap(heap[i],heap[smallest]);
            i=smallest;
        }
    }
public:
    void push(int x){
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
    void pop(){
        if(heap.empty())return ;
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top(){return heap[0];}
    bool empty(){return heap.empty();}
    int size(){return heap.size();}
};
int main (){
    MinPQ pq;
    pq.push(10);
    pq.push(4);
    pq.push(15);
    pq.push(20);
    pq.push(2);
    std::cout << pq.top() << "\n";
    pq.pop();
    std::cout << pq.top()<<"\n";
    return 0;
}
