/*
Sort a linked list using insertion sort.
*/
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
    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode **newh = &head;
        ListNode **cur = &(head->next);
        while(*cur) {
            ListNode **p = newh;
            while(p != cur) {
                if((*p)->val > (*cur)->val) break;
                p = &((*p)->next);
            }
            if(p != cur) {
                ListNode *tmp = (*cur)->next;
                (*cur)->next = *p;
                *p = *cur;
                *cur = tmp;
            }
            else cur = &((*cur)->next);
        }
        return head;
    }
};