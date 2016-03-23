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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *newh = NULL, *cur = head, *pre;
        ListNode **tail = &newh;
        while(cur) {
            pre = cur;
            while(cur->next && cur->val==cur->next->val) {
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
            if(pre == cur) {
                *tail = pre;
                tail = &pre->next;
            }
            cur = cur->next;
        }
        *tail = NULL;
        return newh;
    }
};



class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummy(0);
        dummy.next = head;

        ListNode *pre = &dummy, *cur = head;
        while (cur) {
            int i = cur->val;
            if (cur->next && cur->next->val == i) {
                while (cur && cur->val == i) {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
                cur = pre;
            }
            pre = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};

