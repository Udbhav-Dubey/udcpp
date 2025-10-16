#include <bits/stdc++.h>
using namespace std;
class FrontMiddleBackQueue {
public:
    vector<int>arr;
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
       arr[0]=val; 
    }
    
    void pushMiddle(int val) {
        int n=arr.size();
        int mid=n;
        for (int i=n;i>mid;i++){
            arr[i]=arr[i-1];
        }
        arr[mid]=val;
    }
    
    void pushBack(int val) {
        arr.push_back(val);
    }
    
    int popFront() {
        if (arr.empty()){return -1;}
        int temp=arr[0];
        //arr.pop_front();
        for (int i=0;i<arr.size();i++){
            arr[i]=arr[i+1];
        }
        return temp;
    }
    
    int popMiddle() {
        if (arr.empty()){return -1;}
        int n=arr.size();
        int mid=n/2;
        if (n%2==0){
            mid=mid-1;
        }
        int temp=arr[mid];
        for (int i=mid;i<n;i++){
            arr[i]=arr[i+1];
        }
        return temp;
    }
    
    int popBack() {
        if (arr.empty()){return -1;}
        int n=arr.size();
        int temp=arr[n-1];
        arr.pop_back();
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
