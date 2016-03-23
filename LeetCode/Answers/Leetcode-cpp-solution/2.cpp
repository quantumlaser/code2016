/*
Add Two NumbersNov 1 '118434 / 28715

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head;
        ListNode **tail = &head;
        int carry = 0;
        while(l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum/10;
            sum %= 10;
            *tail = new ListNode(sum);
            tail = &(*tail)->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head;
        ListNode **tail = &head;
        int carry = 0;
        while(l1 || l2 || carry) {
            int sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            carry = sum/10;
            sum %= 10;
            *tail = new ListNode(sum);
            tail = &(*tail)->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head;
    }
};