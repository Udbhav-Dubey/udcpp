#include<bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*curr1=l1;
        ListNode*curr2=l2;
        while(curr1!=nullptr || curr2!=nullptr){
            curr1->val+=curr2->val;
            if (curr1->val>=10{int temp=curr1->val}
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return l1;
    }
};
