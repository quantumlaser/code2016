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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(0);
        ListNode *cur = head, *pre = &dummy, *tail = &dummy;
        dummy.next = head;
        while(cur) {
            if(cur->val < x) {
                if(pre != tail) {
                    pre->next = cur->next;
                    cur->next = tail->next;
                    tail->next = cur;
                    cur = pre;
                }
                tail = tail->next;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(!head || !head->next) return head;
        ListNode **cur = &head, **tail = &head;
        while(*cur) {
            if((*cur)->val < x) {
                if(*tail != *cur) {
                    ListNode *tmp = (*cur)->next;
                    (*cur)->next = *tail;
                    *tail = *cur;
                    *cur = tmp;
                }
                else cur = &((*cur)->next);
                tail = &((*tail)->next);
            }
            else cur = &((*cur)->next);
        }
        return head;
    }
};