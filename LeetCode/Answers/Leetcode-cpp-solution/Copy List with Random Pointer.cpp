/*
Copy List with Random Pointer
AC Rate: 1212/6176
My Submissions

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void cloneNode(RandomListNode *head) {
        RandomListNode *pNode = head;
        while(pNode) {
            RandomListNode *pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    void connectSibling(RandomListNode *head) {
        RandomListNode *pNode = head;
        while(pNode) {
            if(pNode->random) pNode->next->random = pNode->random->next;
            pNode = pNode->next->next;
        }
    }
    RandomListNode* detach(RandomListNode *head) {
        if(!head || !head->next) return NULL;
        RandomListNode *pNode = head;
        RandomListNode *pClonedHead = head->next, *pClonedNode = head->next;
        pNode->next = pClonedNode->next;
        pNode = pNode->next;
        while(pNode) {
            pClonedNode->next = pNode->next;
            pClonedNode =  pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        cloneNode(head);
        connectSibling(head);
        return detach(head);
    }
};

