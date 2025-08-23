class LRUCache {
    private:
        struct Node{
            int key,value;
            Node*next;*prev;
            Node(int k,int v){
                this key->k;
                this v->v;
                this prev=nullptr;
                this next=nullptr;
            }
        };
        int capacity;
        unordered_map<int,Node*> cache;
        Node*head,*tail;
        void addNode(Node* node){
            node->prev=head;
            node->next=head->next;
            head->next->prev=node;
            head->next=node;
        }
        void removal(Node* node){
            Node* prev=node->prev;
            Node* next=node->next;
            prev->next=next;
            next->prev=prev;
        }
        void movetoHead(Node*node){
            removeNode(node);
            addNode(node);
        } 
        Node* poptail(){
            Node* node=tail->prev;
            removeNode(node);
            return node;
        }
    public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
     if (cache.find(key)==cache.end()){
        return -1;
     }
     Node*node=cache[key];
     movetohead(node);
     return node->value;
    }
    void put(int key, int value) {
     if (cache.find(key)!=cache.end()){
        Node*node=cache[key];
        node->value=value;
        movetoHead(node);
     }   
     else{
        Node* node=new Node(key,value);
        cache[key]=node;
        addNode(node);

        if ((int)cache.size()>capacity){
            Node*tailNode=poptail();
            cache.erase(tailNode->key);
            delete tailNode;
        }
     }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
