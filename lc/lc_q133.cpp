class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==nullptr){return nullptr;}
        unordered_map<Node*,Node*> hmap;
        queue <Node*>q;
        q.push(node);
        Node* node1=new Node(node->val);
        hmap[node]=node1;
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            Node*temp2=hmap[temp];
            for (auto i:temp->neighbors){
                if (hmap.find(i)==hmap.end()){
                Node* tmp= new Node(i->val);
                //temp2->neighbors.push_back(tmp);
                hmap[i]=tmp;
                q.push(i);
                }
                temp2->neighbors.push_back(hmap[i]);
            }
        }
        return node1;
    }
};
