#include <iostream>
#include <vector>
class Node{
public:
    int data;
    std::vector <Node*>children;
    Node(int x){
        this->data=x;
    }
};
void addChild(Node*parent,Node*child){
    parent->children.push_back(child);
}
void printParents(Node*node,Node*parent){
    if (parent==nullptr){std::cout << node->data<<"-> NULL" << std::endl;}
    else {std::cout << node->data<<" -> "<<parent->data<<std::endl;}
    for (auto child:node->children){
        printParents(child,node);
    }
}
void printChildren(Node*node){
    std::cout << node->data << " -> ";
    for (auto child:node->children){
        std::cout << child->data<<" ";
    }
    std::cout << std::endl;
    for (auto child:node->children){
        printChildren(child);
    }
}
void printLeafNodes(Node*node){
    if (node->children.empty()){
        std::cout << node->data<<" ";
        return ;
    }
    for (auto child:node->children){
        printLeafNodes(child);
    }
}
void printDegrees(Node*node,Node*parent){
    int degree=node->children.size();
    if (parent!=nullptr){
        degree++;
    }
    std::cout << node->data << " -> " << degree << std::endl;
    for (auto child:node->children){
        printDegrees(child,node);
    }
}
int main (){
    Node*root=new Node(1);
    Node*n2=new Node(2);
    Node*n3=new Node(3);
    Node*n4=new Node(4);
    Node*n5=new Node(5);

    addChild(root,n2);
    addChild(root,n3);
    addChild(n2,n4);
    addChild(n2,n5);
    std::cout << "Parent of each node:" << std::endl;
    printParents(root,nullptr);
    std::cout << "children of each node:" << std::endl;
    printChildren(root);
    std::cout << "Leaf nodes:";
    printLeafNodes(root);
    std::cout << std::endl;
    std::cout << "Degree of each node : " << std::endl;
    printDegrees(root,nullptr);
    return 0;
}
