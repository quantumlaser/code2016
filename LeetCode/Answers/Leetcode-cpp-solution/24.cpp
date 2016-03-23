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
    ListNode *swapPairs(ListNode *head) {
        ListNode **tail = &head;
        ListNode *cur = head;
        while(cur&&cur->next) {
            *tail = cur->next;
            cur->next = (*tail)->next;
            (*tail)->next = cur;
            tail = &(cur->next);
            cur = cur->next;
        }
        return head;
    }
};

class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            ListNode *root = new ListNode(0);
            ListNode *p = head, *t = root;
            while(p && p->next) {
                t->next = p->next;
                p->next = t->next->next;
                t->next->next = p;
                t = p;
                p = p->next;
            }
            if(p) t->next = p;
            ListNode *rem = root;
            root = root->next;
            delete rem;
            return root;
        }
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **p = &head;
        while(*p && (*p)->next) {
            ListNode *cur = *p;
            *p = cur->next;
            cur->next = (*p)->next;
            (*p)->next = cur;
            p = &(cur->next);
        }
        return head;
    }
};