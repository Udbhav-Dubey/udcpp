#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*curr=head;
        while(curr!=nullptr){
            if (curr->next==nullptr){break;}
            if (curr->val == curr->next->val ){
                curr->next=curr->next->next;
            }
            else curr=curr->next;
        }
        return head;
    }
};
