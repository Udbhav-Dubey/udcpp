#include <bits/stdc++.h>
using namespace std;
class solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr){return nullptr;}
        if (head->next==nullptr){return head;}
        ListNode dummy(0);
        dummy.next=head;
        ListNode*prev=&dummy;
        while(prev->next&&prev->next->next){
            ListNode*first=prev->next;
            ListNode*second=prev->next->next;
            first->next=second->next;
            prev->next=second;
            prev=first;
        }
        return dummy.next;
    }
};
