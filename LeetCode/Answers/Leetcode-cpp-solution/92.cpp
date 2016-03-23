/*
Reverse Linked List IIJun 27 '125508 / 18773

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode newh(0);
        newh.next = head;
        ListNode *pre = &newh, *preM, *cur=head;
        for(int i=1; i<=n; ++i) {
            if(i==m) preM = pre;
            if(i>m) {
                ListNode *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        preM->next->next = cur;
        preM->next = pre;
        return newh.next;
    }

};