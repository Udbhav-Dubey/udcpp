#include <iostream>
#include <vector>
class MaxPQ{
    std::vector<int>heap;
    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    void heapifyUp(int i){
        while(i>0&&heap[parent(i)]<heap[i]){
            std::swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    void heapifyDown(int i){
        int n=heap.size();
        while(true){
            int l=left(i),r=right(i);
            int largest=i;
            if (l<n&&heap[l]>heap[largest]){
                largest=l;
            }
            if (r<n&&heap[r]>heap[largest]){
                largest=r;
            }
            if (largest==i)break;
            std::swap(heap[i],heap[largest]);
            i=largest;
        }
    }
public:
    void push(int x){
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
    void pop(){
        if (heap.empty())return ;
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top(){return heap[0];}
    bool empty(){return heap.empty();}
    int size(){return heap.size();}
};
int main (){
    MaxPQ pq;
    pq.push(10);
    pq.push(4);
    pq.push(15);
    pq.push(20);
    std::cout << pq.top() << "\n";
    pq.pop();
    std::cout << pq.top() << "\n";
    return 0;
}
