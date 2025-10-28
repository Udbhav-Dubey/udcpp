#include <iostream>
#include <vector>
class Node{
    public:
        int data;
        Node*lchild;
        Node*rchild;
        Node(int key){
            this->data=key;
            lchild=nullptr;
            rchild=nullptr;
        }
};
int main (){
    Node*firstNode=new Node(2);
    Node*secondNode=new Node(3);
    Node*thirdNode=new Node(4);
    Node*fourthNode=new Node(5);
    firstNode->lchild=secondNode;
    secondNode->lchild=fourthNode;
    firstNode->rchild=thirdNode;
    return 0;

}
