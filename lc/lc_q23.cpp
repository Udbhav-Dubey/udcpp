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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode*mergeTwoLists(ListNode* l1,ListNode* l2){
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeRange(vector<ListNode*>&lists,int left,int right){
        if (left>right) return nullptr;
        if (left==right) return lists[left];
        int mid=left+(right-left)/2;
        ListNode*l1=mergeRange(lists,left,mid);
        ListNode*l2=mergeRange(lists,mid+1,right);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists,0,(int)lists.size()-1);
        }
    }
};
