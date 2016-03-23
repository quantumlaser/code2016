/**
Remove Nth Node From End of ListJan 28 '12558 / 1490

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head, **slow = &head;
        while(--n) p = p->next;
        while(p->next) {
            p = p->next;
            slow = &((*slow)->next);
        }
        ListNode *tmp = *slow;
        *slow = (*slow)->next;
        delete tmp;
        return head;
    }
};
 //24ms
 class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head) return NULL;
        ListNode *p = head, *q = head;
        ListNode **tail = &head;
        while(--n) q = q->next;
        while(q->next) {
            tail = &(p->next);
            p = p->next;
            q = q->next;
        }
        *tail = p->next;
        delete p;
        return head;
    }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p=head, *q=head;
        if(!head) return NULL;
        ListNode **tail = &head;
        while(n--) q = q->next;
        while(q) {
            tail = &(p->next);
            p = p->next;
            q = q->next;
        }
        *tail = p->next;
        delete p;
        return head;
    }
};
//40ms
class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode *p = head, *q = head, *pre;
            for(int i=1; i<n; ++i, q=q->next); 
            if(!q->next) {
                pre = head;
                head = pre->next;
                delete pre;
                return head;
            }
            while(q->next) {
                pre = p;
                p = p->next;
                q = q->next;
            }
            pre->next = p->next;
            delete p;
            return head;
        }
};
//44ms
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p, *q;
        p = q = head;
        while(n--) q = q->next;
        if(!q) {
            head = p->next;
            delete p;
            return head;
        }
        while(q->next) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};