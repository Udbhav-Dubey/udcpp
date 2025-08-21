#include <iostream>
#include <unordered_map>
class Solution {
public :
        Node* copyRandomList(Node*head){
            if (!head) return nullptr;
            std::unordered_map<Node*,Node*> oldtoNew;
            Node*curr=head;
            while(curr){
                oldtoNew[curr]=new Node(curr->val);
                curr=curr->next;
            }
            curr=head;
            while(curr){
                Node*copy=oldtoNew[curr];
                copy->next=curr->next?oldtoNew[curr->next]:nullptr;
                copy->random=curr->random?olttoNew[curr->random]:nullptr;
                curr=curr->next;
            }
            return oltToNew[head];
        }
};
