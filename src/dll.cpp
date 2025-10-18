struct Node(){
int data;
Node*prev;
Node*next;
Node(int data){
    this->data=data;
    this->prev=nullptr;
    this->next=nullptr;
}
};
