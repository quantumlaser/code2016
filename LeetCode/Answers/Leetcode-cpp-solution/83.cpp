class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if(!head || !head->next) return head;
            ListNode *pre = head, *cur = head->next;
            while(cur) {
                if(pre->val == cur->val) {
                    cur = cur->next;
                    delete pre->next;
                    pre->next = cur;
                }
                else {
                    pre = cur;
                    cur = cur->next;
                }
            }
            return head;
        }
};
