/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0), *t = root;
        while(l1&&l2) {
            if(l1->val <= l2->val) {
                t->next = l1;
                l1 = l1->next;
            }
            else {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        if(l1) t->next = l1;
        if(l2) t->next = l2;
        ListNode *dumb = root;
        root = root->next;
        delete dumb;
        return root;
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode **p = &head;
        while(l1&&l2) {
            if(l1->val <= l2->val) {
                *p = l1;
                l1 = l1->next;
            }
            else {
                *p = l2;
                l2 = l2->next;
            }
            p = &((*p)->next);
        }
        *p = l1 ? l1 : l2;
        //if(l1) *p=l1;
        //if(l2) *p=l2;
        return head;
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL;
        ListNode **tail = &head;
        while(l1 && l2) {
            ListNode **newl = (l1->val < l2->val) ? &l1 : &l2;
            *tail = *newl;
            *newl = (*newl)->next;
            tail = &((*tail)->next);
        }
        *tail = l1 ? l1 : l2;
        return head;
    }
};