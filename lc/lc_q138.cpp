#include <bits/stdc++.h>
using namespace std;
class Solution {
    public :
        Node* copyRandomList(Node*head){
            if (!head) return nullptr;
            unordered_map<Node*,Node*> map;
            Node*copy_head=new Node(head->val);
            Node*randm=new Node(head->random->val);
            Node*nxt=new Node(head->next->val);
            map[head]=copy_head;
            copy_head->random=randm;
            copy_head->next=nxt;
            curr=curr->next;
            Node*ncurr=copy_head;
            ncurr=ncurr->next;
            while(curr!=nullptr){
                if (curr->next==nullptr){
                    ncurr->next=nullptr;
                }
                if (map.find(curr->next)!=map.end){
                Node*newnode= new Node(curr->val);
                }
                else {Node*newnode=map[curr->next];}
                ncurr->next=newnode;
                if (curr->random==nullptr){
                    newnode->random=nullptr;
                }
                else { newnode->random=curr->random; }
                map[curr]=newnode;
                curr=curr->next;
            }
            return copy_head;
        }
};
